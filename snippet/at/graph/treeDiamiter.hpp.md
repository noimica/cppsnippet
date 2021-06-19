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
  bundledCode: "#line 1 \"snippet/at/graph/treeDiamiter.hpp\"\n//\u6728\u306E\u76F4\
    \u5F84\u3092\u6C42\u3081\u308B\r\nll treeDiamiter(const graph& g){\r\n    auto\
    \ u=BFS(g, 0);\r\n    ll mx=0;\r\n    EACH(x, u){\r\n        if(u[mx]<x.se){\r\
    \n            mx=x.fi;\r\n        }\r\n    }\r\n    auto v=BFS(g, mx);\r\n   \
    \ EACH(x, v){\r\n        if(v[mx]<x.se){\r\n            mx=x.fi;\r\n        }\r\
    \n    }\r\n    return v[mx];\r\n}\n"
  code: "//\u6728\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\r\nll treeDiamiter(const\
    \ graph& g){\r\n    auto u=BFS(g, 0);\r\n    ll mx=0;\r\n    EACH(x, u){\r\n \
    \       if(u[mx]<x.se){\r\n            mx=x.fi;\r\n        }\r\n    }\r\n    auto\
    \ v=BFS(g, mx);\r\n    EACH(x, v){\r\n        if(v[mx]<x.se){\r\n            mx=x.fi;\r\
    \n        }\r\n    }\r\n    return v[mx];\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/treeDiamiter.hpp
  requiredBy: []
  timestamp: '2021-06-19 19:07:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/treeDiamiter.test.cpp
documentation_of: snippet/at/graph/treeDiamiter.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/treeDiamiter.hpp
- /library/snippet/at/graph/treeDiamiter.hpp.html
title: snippet/at/graph/treeDiamiter.hpp
---
