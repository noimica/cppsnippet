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
  bundledCode: "#line 1 \"snippet/at/graph/tree_diamiter.hpp\"\n//\u6728\u306E\u76F4\
    \u5F84\u3092\u6C42\u3081\u308B\r\nll tree_diamiter(const graph& g){\r\n    auto\
    \ u=bfs(g, 0);\r\n    ll mx=0;\r\n    EACH(x, u){\r\n        if(u[mx]<x.se){\r\
    \n            mx=x.fi;\r\n        }\r\n    }\r\n    auto v=bfs(g, mx);\r\n   \
    \ EACH(x, v){\r\n        if(v[mx]<x.se){\r\n            mx=x.fi;\r\n        }\r\
    \n    }\r\n    return v[mx];\r\n}\n"
  code: "//\u6728\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\r\nll tree_diamiter(const\
    \ graph& g){\r\n    auto u=bfs(g, 0);\r\n    ll mx=0;\r\n    EACH(x, u){\r\n \
    \       if(u[mx]<x.se){\r\n            mx=x.fi;\r\n        }\r\n    }\r\n    auto\
    \ v=bfs(g, mx);\r\n    EACH(x, v){\r\n        if(v[mx]<x.se){\r\n            mx=x.fi;\r\
    \n        }\r\n    }\r\n    return v[mx];\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/tree_diamiter.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/graph/tree_diamiter.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/tree_diamiter.hpp
- /library/snippet/at/graph/tree_diamiter.hpp.html
title: snippet/at/graph/tree_diamiter.hpp
---