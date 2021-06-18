---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/Tsort.test.cpp
    title: test/graph/Tsort.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal.test.cpp
    title: test/graph/kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/prim.test.cpp
    title: test/graph/prim.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/warshall_floyd.test.cpp
    title: test/graph/warshall_floyd.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"snippet/at/graph/graph.hpp\"\n#pragma region graph\r\nstruct\
    \ edge{\r\n    ll from, to, cost;\r\n    bool operator<(const edge& r) const{return\
    \ cost<r.cost;}\r\n    bool operator>(const edge& r) const{return cost>r.cost;}\r\
    \n};\r\nstruct graph{\r\n    ll V;\r\n    vector<vector<edge> > G;\r\n    graph(ll\
    \ n){\r\n        init(n);\r\n    }\r\n    void init(ll n){\r\n        V = n;\r\
    \n        G.resize(V);\r\n    }\r\n    // \u7121\u5411\u30B0\u30E9\u30D5\r\n \
    \   void add_edge(ll s, ll t, ll cost = 1){\r\n        add_diedge(s, t, cost);\r\
    \n        add_diedge(t, s, cost);\r\n    }\r\n    // \u6709\u5411\u30B0\u30E9\u30D5\
    \r\n    void add_diedge(ll s, ll t, ll cost = 1){\r\n        if(s < 0 || t < 0\
    \ || s >= V || t >= V) return;\r\n        G[s].push_back({s, t, cost});\r\n  \
    \  }\r\n    auto pos2d(ll height, ll width){\r\n        return [height, width](ll\
    \ y, ll x){\r\n            return \r\n                (y < 0 || y >= height ||\
    \ x < 0 || x >= width)\r\n                ? -1\r\n                : y*width +\
    \ x;\r\n        };\r\n    }\r\n};\r\n#pragma endregion\n"
  code: "#pragma region graph\r\nstruct edge{\r\n    ll from, to, cost;\r\n    bool\
    \ operator<(const edge& r) const{return cost<r.cost;}\r\n    bool operator>(const\
    \ edge& r) const{return cost>r.cost;}\r\n};\r\nstruct graph{\r\n    ll V;\r\n\
    \    vector<vector<edge> > G;\r\n    graph(ll n){\r\n        init(n);\r\n    }\r\
    \n    void init(ll n){\r\n        V = n;\r\n        G.resize(V);\r\n    }\r\n\
    \    // \u7121\u5411\u30B0\u30E9\u30D5\r\n    void add_edge(ll s, ll t, ll cost\
    \ = 1){\r\n        add_diedge(s, t, cost);\r\n        add_diedge(t, s, cost);\r\
    \n    }\r\n    // \u6709\u5411\u30B0\u30E9\u30D5\r\n    void add_diedge(ll s,\
    \ ll t, ll cost = 1){\r\n        if(s < 0 || t < 0 || s >= V || t >= V) return;\r\
    \n        G[s].push_back({s, t, cost});\r\n    }\r\n    auto pos2d(ll height,\
    \ ll width){\r\n        return [height, width](ll y, ll x){\r\n            return\
    \ \r\n                (y < 0 || y >= height || x < 0 || x >= width)\r\n      \
    \          ? -1\r\n                : y*width + x;\r\n        };\r\n    }\r\n};\r\
    \n#pragma endregion"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/graph.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graph/dijkstra.test.cpp
  - test/graph/prim.test.cpp
  - test/graph/Tsort.test.cpp
  - test/graph/warshall_floyd.test.cpp
  - test/graph/kruskal.test.cpp
documentation_of: snippet/at/graph/graph.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/graph.hpp
- /library/snippet/at/graph/graph.hpp.html
title: snippet/at/graph/graph.hpp
---
