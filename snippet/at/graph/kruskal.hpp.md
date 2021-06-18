---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal.test.cpp
    title: test/graph/kruskal.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"snippet/at/graph/kruskal.hpp\"\n#pragma region kruskal\r\
    \npair<ll, graph> kruskal(ll V, vector<edge>& edges, ll K = 0){\r\n    UnionFind\
    \ uf(V);\r\n    graph r(V);\r\n    sort(edges.begin(), edges.end());\r\n    ll\
    \ sum = 0;\r\n    EACH(e, edges){\r\n        if(K <= 0) break;\r\n        auto\
    \ [f, t, c] = e;\r\n        if(uf.same(f, t)) continue;\r\n        r.add_edge(f,\
    \ t, c);\r\n        uf.unite(f, t);\r\n        sum += c;\r\n        K--;\r\n \
    \   }\r\n    return {sum, r};\r\n}\r\n\r\npair<ll, graph> kruskal(const graph&\
    \ g, ll K = 0){\r\n    vector<edge> edges;\r\n    K = g.V - K; // \u5F35\u308B\
    \u8FBA\u306E\u6700\u5927\u5024\r\n    REP(i, g.V){\r\n        EACH(e, g.G[i]){\r\
    \n            if(e.to <= i) continue;\r\n            edges.push_back(e);\r\n \
    \       }\r\n    }\r\n    return kruskal(g.V, edges, K);\r\n}\r\n#pragma endregion\n"
  code: "#pragma region kruskal\r\npair<ll, graph> kruskal(ll V, vector<edge>& edges,\
    \ ll K = 0){\r\n    UnionFind uf(V);\r\n    graph r(V);\r\n    sort(edges.begin(),\
    \ edges.end());\r\n    ll sum = 0;\r\n    EACH(e, edges){\r\n        if(K <= 0)\
    \ break;\r\n        auto [f, t, c] = e;\r\n        if(uf.same(f, t)) continue;\r\
    \n        r.add_edge(f, t, c);\r\n        uf.unite(f, t);\r\n        sum += c;\r\
    \n        K--;\r\n    }\r\n    return {sum, r};\r\n}\r\n\r\npair<ll, graph> kruskal(const\
    \ graph& g, ll K = 0){\r\n    vector<edge> edges;\r\n    K = g.V - K; // \u5F35\
    \u308B\u8FBA\u306E\u6700\u5927\u5024\r\n    REP(i, g.V){\r\n        EACH(e, g.G[i]){\r\
    \n            if(e.to <= i) continue;\r\n            edges.push_back(e);\r\n \
    \       }\r\n    }\r\n    return kruskal(g.V, edges, K);\r\n}\r\n#pragma endregion"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/kruskal.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/kruskal.test.cpp
documentation_of: snippet/at/graph/kruskal.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/kruskal.hpp
- /library/snippet/at/graph/kruskal.hpp.html
title: snippet/at/graph/kruskal.hpp
---
