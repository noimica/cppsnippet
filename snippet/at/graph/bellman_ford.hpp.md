---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"snippet/at/graph/bellman_ford.hpp\"\n#pragma region bellman_ford\r\
    \n// O(|E||V|)\r\npair<bool, umap<ll, ll>> bellman_ford(int V, const vector<edge>\
    \ &edges, int s){\r\n    vector<ll> dist(V, INF);\r\n    umap<ll, ll> ret;\r\n\
    \    ret[s] = dist[s] = 0;\r\n    bool is_negative_cycle = true;\r\n    REP(cnt,\
    \ V){\r\n        bool end = true;\r\n        for (auto e : edges) {\r\n      \
    \      if (dist[e.from] != INF && dist[e.from] + e.cost < dist[e.to]) {\r\n  \
    \              ret[e.to] = dist[e.to] = dist[e.from] + e.cost;\r\n           \
    \     end = false;\r\n            }\r\n        }\r\n        if (end){\r\n    \
    \        // \u3053\u3053\u3067\u629C\u3051\u306A\u304B\u3063\u305F\u3089\u8CA0\
    \u306E\u9589\u8DEF\u304C\u3042\u308B\r\n            is_negative_cycle = false;\r\
    \n            break;\r\n        }\r\n    }\r\n    return {is_negative_cycle, ret};\r\
    \n}\r\npair<bool, umap<ll, ll>> bellman_ford(const graph& g, int s) {\r\n    int\
    \ V = g.V;\r\n    vector<edge> edges;\r\n    REP(i, V){\r\n        for(auto e\
    \ : g.G[i]){\r\n            edges.emplace_back(e);\r\n        }\r\n    }\r\n \
    \   return bellman_ford(V, edges, s);\r\n}\r\n#pragma endregion\n"
  code: "#pragma region bellman_ford\r\n// O(|E||V|)\r\npair<bool, umap<ll, ll>> bellman_ford(int\
    \ V, const vector<edge> &edges, int s){\r\n    vector<ll> dist(V, INF);\r\n  \
    \  umap<ll, ll> ret;\r\n    ret[s] = dist[s] = 0;\r\n    bool is_negative_cycle\
    \ = true;\r\n    REP(cnt, V){\r\n        bool end = true;\r\n        for (auto\
    \ e : edges) {\r\n            if (dist[e.from] != INF && dist[e.from] + e.cost\
    \ < dist[e.to]) {\r\n                ret[e.to] = dist[e.to] = dist[e.from] + e.cost;\r\
    \n                end = false;\r\n            }\r\n        }\r\n        if (end){\r\
    \n            // \u3053\u3053\u3067\u629C\u3051\u306A\u304B\u3063\u305F\u3089\u8CA0\
    \u306E\u9589\u8DEF\u304C\u3042\u308B\r\n            is_negative_cycle = false;\r\
    \n            break;\r\n        }\r\n    }\r\n    return {is_negative_cycle, ret};\r\
    \n}\r\npair<bool, umap<ll, ll>> bellman_ford(const graph& g, int s) {\r\n    int\
    \ V = g.V;\r\n    vector<edge> edges;\r\n    REP(i, V){\r\n        for(auto e\
    \ : g.G[i]){\r\n            edges.emplace_back(e);\r\n        }\r\n    }\r\n \
    \   return bellman_ford(V, edges, s);\r\n}\r\n#pragma endregion"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2021-06-18 19:34:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/graph/bellman_ford.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/bellman_ford.hpp
- /library/snippet/at/graph/bellman_ford.hpp.html
title: snippet/at/graph/bellman_ford.hpp
---