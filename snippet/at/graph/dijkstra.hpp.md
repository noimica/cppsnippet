---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"snippet/at/graph/dijkstra.hpp\"\n// O(|E|log|V|)\r\numap<ll,\
    \ ll> dijkstra(const graph& g, ll s){\r\n    vector<ll> d(g.V, INF);\r\n    umap<ll,\
    \ ll> ret;\r\n    ret[s] = d[s] = 0;\r\n    priority_queue<P,vector<P>, greater<P>>\
    \ que;\r\n    que.push({0, s});\r\n    while(!que.empty()){\r\n        auto [c,\
    \ v] = que.top(); que.pop();\r\n        if(d[v]<c) continue;\r\n        for(auto\
    \ e : g.G[v]){\r\n            if(d[e.to]>d[v]+e.cost){\r\n                ret[e.to]\
    \ = d[e.to] = d[v]+e.cost;\r\n                que.push({d[e.to],e.to});\r\n  \
    \          }\r\n        }\r\n    }\r\n    return ret;\r\n}\n"
  code: "// O(|E|log|V|)\r\numap<ll, ll> dijkstra(const graph& g, ll s){\r\n    vector<ll>\
    \ d(g.V, INF);\r\n    umap<ll, ll> ret;\r\n    ret[s] = d[s] = 0;\r\n    priority_queue<P,vector<P>,\
    \ greater<P>> que;\r\n    que.push({0, s});\r\n    while(!que.empty()){\r\n  \
    \      auto [c, v] = que.top(); que.pop();\r\n        if(d[v]<c) continue;\r\n\
    \        for(auto e : g.G[v]){\r\n            if(d[e.to]>d[v]+e.cost){\r\n   \
    \             ret[e.to] = d[e.to] = d[v]+e.cost;\r\n                que.push({d[e.to],e.to});\r\
    \n            }\r\n        }\r\n    }\r\n    return ret;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-06-18 19:34:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/dijkstra.test.cpp
documentation_of: snippet/at/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/dijkstra.hpp
- /library/snippet/at/graph/dijkstra.hpp.html
title: snippet/at/graph/dijkstra.hpp
---
