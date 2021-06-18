---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/warshallFloyd.test.cpp
    title: test/graph/warshallFloyd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"snippet/at/graph/warshallFloyd.hpp\"\n#pragma region warshallFloyd\r\
    \n// O(|V|^3)\r\npair<bool, vector<vector<ll>>> warshallFloyd(const vector<vector<ll>>\
    \ &_dist){\r\n    int V = _dist.size();\r\n    vector<vector<ll>> dist(_dist);\r\
    \n    REP(k, V) {\r\n        REP(i, V) {\r\n            REP(j, V) {\r\n      \
    \          if(dist[i][k] == INF || dist[k][j] == INF) continue;\r\n          \
    \      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);\r\n            }\r\
    \n        }\r\n    }\r\n    bool is_negative_cycle = false;\r\n    REP(i, V){\r\
    \n        if(dist[i][i] < 0){\r\n            is_negative_cycle = true;break;\r\
    \n        }\r\n    }\r\n    return {is_negative_cycle, dist};\r\n}\r\npair<bool,\
    \ vector<vector<ll>>> warshallFloyd(const graph& g) {\r\n    int V = g.V;\r\n\
    \    vector<vector<ll>> dist(V, vector<ll>(V, INF));\r\n    REP(i, V){\r\n   \
    \     dist[i][i] = 0;\r\n        for(auto e : g.G[i]){\r\n            dist[i][e.to]\
    \ = e.cost;\r\n        }\r\n    }\r\n    return warshallFloyd(dist);\r\n}\r\n\
    #pragma endregion\n"
  code: "#pragma region warshallFloyd\r\n// O(|V|^3)\r\npair<bool, vector<vector<ll>>>\
    \ warshallFloyd(const vector<vector<ll>> &_dist){\r\n    int V = _dist.size();\r\
    \n    vector<vector<ll>> dist(_dist);\r\n    REP(k, V) {\r\n        REP(i, V)\
    \ {\r\n            REP(j, V) {\r\n                if(dist[i][k] == INF || dist[k][j]\
    \ == INF) continue;\r\n                dist[i][j] = min(dist[i][j], dist[i][k]\
    \ + dist[k][j]);\r\n            }\r\n        }\r\n    }\r\n    bool is_negative_cycle\
    \ = false;\r\n    REP(i, V){\r\n        if(dist[i][i] < 0){\r\n            is_negative_cycle\
    \ = true;break;\r\n        }\r\n    }\r\n    return {is_negative_cycle, dist};\r\
    \n}\r\npair<bool, vector<vector<ll>>> warshallFloyd(const graph& g) {\r\n    int\
    \ V = g.V;\r\n    vector<vector<ll>> dist(V, vector<ll>(V, INF));\r\n    REP(i,\
    \ V){\r\n        dist[i][i] = 0;\r\n        for(auto e : g.G[i]){\r\n        \
    \    dist[i][e.to] = e.cost;\r\n        }\r\n    }\r\n    return warshallFloyd(dist);\r\
    \n}\r\n#pragma endregion"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/warshallFloyd.hpp
  requiredBy: []
  timestamp: '2021-06-18 20:18:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/warshallFloyd.test.cpp
documentation_of: snippet/at/graph/warshallFloyd.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/warshallFloyd.hpp
- /library/snippet/at/graph/warshallFloyd.hpp.html
title: snippet/at/graph/warshallFloyd.hpp
---
