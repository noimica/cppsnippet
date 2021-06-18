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
  bundledCode: "#line 1 \"snippet/at/graph/bfs.hpp\"\n// O(V+E)\r\numap<ll, ll> bfs(const\
    \ graph& g, ll s, ll limit = INF){\r\n    vector<ll> d(g.V, INF);\r\n    umap<ll,\
    \ ll> ret;\r\n    d[s] = 0;\r\n    queue<P> que;\r\n    que.push({0, s});\r\n\
    \    ret[s] = 0;\r\n    while(!que.empty()){\r\n        auto [c, v] = que.front();\
    \ que.pop();\r\n        if(d[v]<c) continue;\r\n        for(auto e : g.G[v]){\r\
    \n            if(d[e.to]>d[v]+1 && limit>=d[v]+1){\r\n                d[e.to]\
    \ = d[v]+1;\r\n                que.push({d[e.to],e.to});\r\n                ret[e.to]\
    \ = d[e.to];\r\n            }\r\n        }\r\n    }\r\n    return ret;\r\n}\n"
  code: "// O(V+E)\r\numap<ll, ll> bfs(const graph& g, ll s, ll limit = INF){\r\n\
    \    vector<ll> d(g.V, INF);\r\n    umap<ll, ll> ret;\r\n    d[s] = 0;\r\n   \
    \ queue<P> que;\r\n    que.push({0, s});\r\n    ret[s] = 0;\r\n    while(!que.empty()){\r\
    \n        auto [c, v] = que.front(); que.pop();\r\n        if(d[v]<c) continue;\r\
    \n        for(auto e : g.G[v]){\r\n            if(d[e.to]>d[v]+1 && limit>=d[v]+1){\r\
    \n                d[e.to] = d[v]+1;\r\n                que.push({d[e.to],e.to});\r\
    \n                ret[e.to] = d[e.to];\r\n            }\r\n        }\r\n    }\r\
    \n    return ret;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/bfs.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/graph/bfs.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/bfs.hpp
- /library/snippet/at/graph/bfs.hpp.html
title: snippet/at/graph/bfs.hpp
---
