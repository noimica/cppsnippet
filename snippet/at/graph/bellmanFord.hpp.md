---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bellmanFord.test.cpp
    title: test/graph/bellmanFord.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"snippet/at/graph/bellmanFord.hpp\"\n#pragma region bellmanFord\r\
    \n// O(|E||V|)\r\npair<bool, umap<ll, ll>> bellmanFord(int V, const vector<edge>\
    \ &edges, int s){\r\n    vector<ll> dist(V, INF);\r\n    umap<ll, ll> ret;\r\n\
    \    ret[s] = dist[s] = 0;\r\n    bool is_negative_cycle = true;\r\n    REP(cnt,\
    \ V){\r\n        bool end = true;\r\n        for (auto e : edges) {\r\n      \
    \      if (dist[e.from] != INF && dist[e.from] + e.cost < dist[e.to]) {\r\n  \
    \              ret[e.to] = dist[e.to] = dist[e.from] + e.cost;\r\n           \
    \     end = false;\r\n            }\r\n        }\r\n        if (end){\r\n    \
    \        // \u3053\u3053\u3067\u629C\u3051\u306A\u304B\u3063\u305F\u3089\u8CA0\
    \u306E\u9589\u8DEF\u304C\u3042\u308B\r\n            is_negative_cycle = false;\r\
    \n            break;\r\n        }\r\n    }\r\n    return {is_negative_cycle, ret};\r\
    \n}\r\npair<bool, umap<ll, ll>> bellmanFord(const graph& g, int s) {\r\n    int\
    \ V = g.V;\r\n    vector<edge> edges;\r\n    REP(i, V){\r\n        for(auto e\
    \ : g.G[i]){\r\n            edges.emplace_back(e);\r\n        }\r\n    }\r\n \
    \   return bellmanFord(V, edges, s);\r\n}\r\n#pragma endregion\n"
  code: "#pragma region bellmanFord\r\n// O(|E||V|)\r\npair<bool, umap<ll, ll>> bellmanFord(int\
    \ V, const vector<edge> &edges, int s){\r\n    vector<ll> dist(V, INF);\r\n  \
    \  umap<ll, ll> ret;\r\n    ret[s] = dist[s] = 0;\r\n    bool is_negative_cycle\
    \ = true;\r\n    REP(cnt, V){\r\n        bool end = true;\r\n        for (auto\
    \ e : edges) {\r\n            if (dist[e.from] != INF && dist[e.from] + e.cost\
    \ < dist[e.to]) {\r\n                ret[e.to] = dist[e.to] = dist[e.from] + e.cost;\r\
    \n                end = false;\r\n            }\r\n        }\r\n        if (end){\r\
    \n            // \u3053\u3053\u3067\u629C\u3051\u306A\u304B\u3063\u305F\u3089\u8CA0\
    \u306E\u9589\u8DEF\u304C\u3042\u308B\r\n            is_negative_cycle = false;\r\
    \n            break;\r\n        }\r\n    }\r\n    return {is_negative_cycle, ret};\r\
    \n}\r\npair<bool, umap<ll, ll>> bellmanFord(const graph& g, int s) {\r\n    int\
    \ V = g.V;\r\n    vector<edge> edges;\r\n    REP(i, V){\r\n        for(auto e\
    \ : g.G[i]){\r\n            edges.emplace_back(e);\r\n        }\r\n    }\r\n \
    \   return bellmanFord(V, edges, s);\r\n}\r\n#pragma endregion"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/bellmanFord.hpp
  requiredBy: []
  timestamp: '2021-06-18 20:18:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/bellmanFord.test.cpp
documentation_of: snippet/at/graph/bellmanFord.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/bellmanFord.hpp
- /library/snippet/at/graph/bellmanFord.hpp.html
title: snippet/at/graph/bellmanFord.hpp
---
