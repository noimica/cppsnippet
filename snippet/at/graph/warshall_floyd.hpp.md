---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/warshall_floyd.test.cpp
    title: test/graph/warshall_floyd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"snippet/at/graph/warshall_floyd.hpp\"\n#pragma region warshall_floyd\r\
    \n// O(|V|^3)\r\npair<bool, vector<vector<ll>>> warshall_floyd(const vector<vector<ll>>\
    \ &_dist){\r\n    int V = _dist.size();\r\n    vector<vector<ll>> dist(_dist);\r\
    \n    REP(k, V) {\r\n        REP(i, V) {\r\n            REP(j, V) {\r\n      \
    \          if(dist[i][k] == INF || dist[k][j] == INF) continue;\r\n          \
    \      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);\r\n            }\r\
    \n        }\r\n    }\r\n    bool is_negative_cycle = false;\r\n    REP(i, V){\r\
    \n        if(dist[i][i] < 0){\r\n            is_negative_cycle = true;break;\r\
    \n        }\r\n    }\r\n    return {is_negative_cycle, dist};\r\n}\r\npair<bool,\
    \ vector<vector<ll>>> warshall_floyd(const graph& g) {\r\n    int V = g.V;\r\n\
    \    vector<vector<ll>> dist(V, vector<ll>(V, INF));\r\n    REP(i, V){\r\n   \
    \     dist[i][i] = 0;\r\n        for(auto e : g.G[i]){\r\n            dist[i][e.to]\
    \ = e.cost;\r\n        }\r\n    }\r\n    return warshall_floyd(dist);\r\n}\r\n\
    #pragma endregion\n"
  code: "#pragma region warshall_floyd\r\n// O(|V|^3)\r\npair<bool, vector<vector<ll>>>\
    \ warshall_floyd(const vector<vector<ll>> &_dist){\r\n    int V = _dist.size();\r\
    \n    vector<vector<ll>> dist(_dist);\r\n    REP(k, V) {\r\n        REP(i, V)\
    \ {\r\n            REP(j, V) {\r\n                if(dist[i][k] == INF || dist[k][j]\
    \ == INF) continue;\r\n                dist[i][j] = min(dist[i][j], dist[i][k]\
    \ + dist[k][j]);\r\n            }\r\n        }\r\n    }\r\n    bool is_negative_cycle\
    \ = false;\r\n    REP(i, V){\r\n        if(dist[i][i] < 0){\r\n            is_negative_cycle\
    \ = true;break;\r\n        }\r\n    }\r\n    return {is_negative_cycle, dist};\r\
    \n}\r\npair<bool, vector<vector<ll>>> warshall_floyd(const graph& g) {\r\n   \
    \ int V = g.V;\r\n    vector<vector<ll>> dist(V, vector<ll>(V, INF));\r\n    REP(i,\
    \ V){\r\n        dist[i][i] = 0;\r\n        for(auto e : g.G[i]){\r\n        \
    \    dist[i][e.to] = e.cost;\r\n        }\r\n    }\r\n    return warshall_floyd(dist);\r\
    \n}\r\n#pragma endregion"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2021-06-18 19:34:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/warshall_floyd.test.cpp
documentation_of: snippet/at/graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/warshall_floyd.hpp
- /library/snippet/at/graph/warshall_floyd.hpp.html
title: snippet/at/graph/warshall_floyd.hpp
---
