---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/treeDiamiter.test.cpp
    title: test/graph/treeDiamiter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"snippet/at/graph/BFS.hpp\"\n// O(V+E)\r\numap<ll, ll> BFS(const\
    \ graph& g, ll s, ll limit = INF){\r\n    vector<ll> d(g.V, INF);\r\n    umap<ll,\
    \ ll> ret;\r\n    d[s] = 0;\r\n    queue<P> que;\r\n    que.push({0, s});\r\n\
    \    ret[s] = 0;\r\n    while(!que.empty()){\r\n        auto [c, v] = que.front();\
    \ que.pop();\r\n        if(d[v]<c) continue;\r\n        for(auto e : g.G[v]){\r\
    \n            ll l = d[v]+e.cost;\r\n            if(d[e.to]>l && limit>=l){\r\n\
    \                d[e.to] = l;\r\n                que.push({d[e.to],e.to});\r\n\
    \                ret[e.to] = d[e.to];\r\n            }\r\n        }\r\n    }\r\
    \n    return ret;\r\n}\n"
  code: "// O(V+E)\r\numap<ll, ll> BFS(const graph& g, ll s, ll limit = INF){\r\n\
    \    vector<ll> d(g.V, INF);\r\n    umap<ll, ll> ret;\r\n    d[s] = 0;\r\n   \
    \ queue<P> que;\r\n    que.push({0, s});\r\n    ret[s] = 0;\r\n    while(!que.empty()){\r\
    \n        auto [c, v] = que.front(); que.pop();\r\n        if(d[v]<c) continue;\r\
    \n        for(auto e : g.G[v]){\r\n            ll l = d[v]+e.cost;\r\n       \
    \     if(d[e.to]>l && limit>=l){\r\n                d[e.to] = l;\r\n         \
    \       que.push({d[e.to],e.to});\r\n                ret[e.to] = d[e.to];\r\n\
    \            }\r\n        }\r\n    }\r\n    return ret;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/BFS.hpp
  requiredBy: []
  timestamp: '2021-06-19 22:58:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/treeDiamiter.test.cpp
documentation_of: snippet/at/graph/BFS.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/BFS.hpp
- /library/snippet/at/graph/BFS.hpp.html
title: snippet/at/graph/BFS.hpp
---
