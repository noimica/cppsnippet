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
  bundledCode: "#line 1 \"snippet/at/array/cumsum.hpp\"\n//A\u306E\u7D2F\u7A4D\u548C\
    \u3092\u3068\u308B\uFF0E[l, r)\u306E\u548C\u306FR[r] - R[l]\u3067\u53D6\u308B\u3053\
    \u3068\u304C\u3067\u304D\u308B\uFF0E\r\ntemplate<class T>\r\nvec<T> cumsum(const\
    \ vec<T> &A) {\r\n    vec<T> R(A.size()+1);\r\n    REP(i, A.size()) R[i + 1] =\
    \ R[i] + A[i];\r\n    return R;\r\n}\n"
  code: "//A\u306E\u7D2F\u7A4D\u548C\u3092\u3068\u308B\uFF0E[l, r)\u306E\u548C\u306F\
    R[r] - R[l]\u3067\u53D6\u308B\u3053\u3068\u304C\u3067\u304D\u308B\uFF0E\r\ntemplate<class\
    \ T>\r\nvec<T> cumsum(const vec<T> &A) {\r\n    vec<T> R(A.size()+1);\r\n    REP(i,\
    \ A.size()) R[i + 1] = R[i] + A[i];\r\n    return R;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/array/cumsum.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/array/cumsum.hpp
layout: document
redirect_from:
- /library/snippet/at/array/cumsum.hpp
- /library/snippet/at/array/cumsum.hpp.html
title: snippet/at/array/cumsum.hpp
---
