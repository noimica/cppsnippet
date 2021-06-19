---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/LCA.test.cpp
    title: test/graph/LCA.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"snippet/at/graph/LCA.hpp\"\n// \u6700\u5C0F\u5171\u901A\u7956\
    \u5148\r\n// \u524D\u51E6\u7406 O(NlogN), \u30AF\u30A8\u30EA O(logN)\r\nstruct\
    \ LCA {\r\n    vector<vector<int>> parent;  // parent[k][u]:= u \u306E 2^k \u5148\
    \u306E\u89AA\r\n    vector<int> dist;            // root \u304B\u3089\u306E\u8DDD\
    \u96E2\r\n    LCA(const graph &g, int root = 0) { init(g, root); }\r\n    // \u521D\
    \u671F\u5316\r\n    void init(const graph &g, int root = 0) {\r\n        ll V\
    \ = g.V;\r\n        ll K = __builtin_popcountll(LONG_LONG_MAX) - __builtin_clzll(V)\
    \ + 1;\r\n        parent.assign(K, vector<int>(V, -1));\r\n        dist.assign(V,\
    \ -1);\r\n        dfs(g, root, -1, 0);\r\n        for (int k = 0; k + 1 < K; k++)\
    \ {\r\n            for (int v = 0; v < V; v++) {\r\n                if (parent[k][v]\
    \ < 0) {\r\n                    parent[k + 1][v] = -1;\r\n                } else\
    \ {\r\n                    parent[k + 1][v] = parent[k][parent[k][v]];\r\n   \
    \             }\r\n            }\r\n        }\r\n    }\r\n    // \u6839\u304B\u3089\
    \u306E\u8DDD\u96E2\u30681\u3064\u5148\u306E\u9802\u70B9\u3092\u6C42\u3081\u308B\
    \r\n    void dfs(const graph &g, int v, int p, int d) {\r\n        parent[0][v]\
    \ = p;\r\n        dist[v] = d;\r\n        for (auto e : g.G[v]) {\r\n        \
    \    if (e.to != p) dfs(g, e.to, v, d + 1);\r\n        }\r\n    }\r\n    int query(int\
    \ u, int v) {\r\n        if (dist[u] < dist[v]) swap(u, v);  // u \u306E\u65B9\
    \u304C\u6DF1\u3044\u3068\u3059\u308B\r\n        int K = parent.size();\r\n   \
    \     // LCA \u307E\u3067\u306E\u8DDD\u96E2\u3092\u540C\u3058\u306B\u3059\u308B\
    \r\n        for (int k = 0; k < K; k++) {\r\n            if ((dist[u] - dist[v])\
    \ >> k & 1) {\r\n                u = parent[k][u];\r\n            }\r\n      \
    \  }\r\n        // \u4E8C\u5206\u63A2\u7D22\u3067 LCA \u3092\u6C42\u3081\u308B\
    \r\n        if (u == v) return u;\r\n        for (int k = K - 1; k >= 0; k--)\
    \ {\r\n            if (parent[k][u] != parent[k][v]) {\r\n                u =\
    \ parent[k][u];\r\n                v = parent[k][v];\r\n            }\r\n    \
    \    }\r\n        return parent[0][u];\r\n    }\r\n};\n"
  code: "// \u6700\u5C0F\u5171\u901A\u7956\u5148\r\n// \u524D\u51E6\u7406 O(NlogN),\
    \ \u30AF\u30A8\u30EA O(logN)\r\nstruct LCA {\r\n    vector<vector<int>> parent;\
    \  // parent[k][u]:= u \u306E 2^k \u5148\u306E\u89AA\r\n    vector<int> dist;\
    \            // root \u304B\u3089\u306E\u8DDD\u96E2\r\n    LCA(const graph &g,\
    \ int root = 0) { init(g, root); }\r\n    // \u521D\u671F\u5316\r\n    void init(const\
    \ graph &g, int root = 0) {\r\n        ll V = g.V;\r\n        ll K = __builtin_popcountll(LONG_LONG_MAX)\
    \ - __builtin_clzll(V) + 1;\r\n        parent.assign(K, vector<int>(V, -1));\r\
    \n        dist.assign(V, -1);\r\n        dfs(g, root, -1, 0);\r\n        for (int\
    \ k = 0; k + 1 < K; k++) {\r\n            for (int v = 0; v < V; v++) {\r\n  \
    \              if (parent[k][v] < 0) {\r\n                    parent[k + 1][v]\
    \ = -1;\r\n                } else {\r\n                    parent[k + 1][v] =\
    \ parent[k][parent[k][v]];\r\n                }\r\n            }\r\n        }\r\
    \n    }\r\n    // \u6839\u304B\u3089\u306E\u8DDD\u96E2\u30681\u3064\u5148\u306E\
    \u9802\u70B9\u3092\u6C42\u3081\u308B\r\n    void dfs(const graph &g, int v, int\
    \ p, int d) {\r\n        parent[0][v] = p;\r\n        dist[v] = d;\r\n       \
    \ for (auto e : g.G[v]) {\r\n            if (e.to != p) dfs(g, e.to, v, d + 1);\r\
    \n        }\r\n    }\r\n    int query(int u, int v) {\r\n        if (dist[u] <\
    \ dist[v]) swap(u, v);  // u \u306E\u65B9\u304C\u6DF1\u3044\u3068\u3059\u308B\r\
    \n        int K = parent.size();\r\n        // LCA \u307E\u3067\u306E\u8DDD\u96E2\
    \u3092\u540C\u3058\u306B\u3059\u308B\r\n        for (int k = 0; k < K; k++) {\r\
    \n            if ((dist[u] - dist[v]) >> k & 1) {\r\n                u = parent[k][u];\r\
    \n            }\r\n        }\r\n        // \u4E8C\u5206\u63A2\u7D22\u3067 LCA\
    \ \u3092\u6C42\u3081\u308B\r\n        if (u == v) return u;\r\n        for (int\
    \ k = K - 1; k >= 0; k--) {\r\n            if (parent[k][u] != parent[k][v]) {\r\
    \n                u = parent[k][u];\r\n                v = parent[k][v];\r\n \
    \           }\r\n        }\r\n        return parent[0][u];\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/LCA.hpp
  requiredBy: []
  timestamp: '2021-06-19 22:58:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/LCA.test.cpp
documentation_of: snippet/at/graph/LCA.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/LCA.hpp
- /library/snippet/at/graph/LCA.hpp.html
title: snippet/at/graph/LCA.hpp
---
