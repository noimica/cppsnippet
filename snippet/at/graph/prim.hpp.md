---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/prim.test.cpp
    title: test/graph/prim.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"snippet/at/graph/prim.hpp\"\npair<ll, graph> prim(const\
    \ graph& g){\r\n    graph r(g.V);\r\n    priority_queue<edge, vector<edge>, greater<edge>>\
    \ que;\r\n    que.push({-1, 0, 0});\r\n    ll sum = 0;\r\n    while(!que.empty()){\r\
    \n        auto [f, t, c] = que.top(); que.pop();\r\n        if(r.G[t].size() >\
    \ 0) continue;\r\n        if(f != -1) r.add_edge(f, t, c);\r\n        sum += c;\r\
    \n        for(auto& e: g.G[t]){\r\n            if(r.G[e.to].size() > 0) continue;\r\
    \n            que.push(e);\r\n        }\r\n    }\r\n    return {sum, r};\r\n}\n"
  code: "pair<ll, graph> prim(const graph& g){\r\n    graph r(g.V);\r\n    priority_queue<edge,\
    \ vector<edge>, greater<edge>> que;\r\n    que.push({-1, 0, 0});\r\n    ll sum\
    \ = 0;\r\n    while(!que.empty()){\r\n        auto [f, t, c] = que.top(); que.pop();\r\
    \n        if(r.G[t].size() > 0) continue;\r\n        if(f != -1) r.add_edge(f,\
    \ t, c);\r\n        sum += c;\r\n        for(auto& e: g.G[t]){\r\n           \
    \ if(r.G[e.to].size() > 0) continue;\r\n            que.push(e);\r\n        }\r\
    \n    }\r\n    return {sum, r};\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/prim.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/prim.test.cpp
documentation_of: snippet/at/graph/prim.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/prim.hpp
- /library/snippet/at/graph/prim.hpp.html
title: snippet/at/graph/prim.hpp
---
