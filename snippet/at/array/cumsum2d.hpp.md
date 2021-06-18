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
  bundledCode: "#line 1 \"snippet/at/array/cumsum2d.hpp\"\n// [x1, x2) x [y1, y2)\
    \ \u306F\r\n// s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1]\r\n// \u3067\u6C42\
    \u307E\u308B\r\nvec<vl> cumsum2d(const vec<vl>& a){\r\n    ll H = a.size(), W\
    \ = a[0].size();\r\n    vec<vl> s(H+1, vl(W+1));\r\n    REP(i, H){\r\n       \
    \ REP(j, W){\r\n            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];\r\
    \n        }\r\n    }\r\n    return s;\r\n}\n"
  code: "// [x1, x2) x [y1, y2) \u306F\r\n// s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1]\r\
    \n// \u3067\u6C42\u307E\u308B\r\nvec<vl> cumsum2d(const vec<vl>& a){\r\n    ll\
    \ H = a.size(), W = a[0].size();\r\n    vec<vl> s(H+1, vl(W+1));\r\n    REP(i,\
    \ H){\r\n        REP(j, W){\r\n            s[i+1][j+1] = s[i][j+1] + s[i+1][j]\
    \ - s[i][j] + a[i][j];\r\n        }\r\n    }\r\n    return s;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/array/cumsum2d.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/array/cumsum2d.hpp
layout: document
redirect_from:
- /library/snippet/at/array/cumsum2d.hpp
- /library/snippet/at/array/cumsum2d.hpp.html
title: snippet/at/array/cumsum2d.hpp
---
