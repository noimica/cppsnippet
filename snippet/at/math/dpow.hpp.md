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
  bundledCode: "#line 1 \"snippet/at/math/dpow.hpp\"\nll dpow(ll x, ll n, int mod\
    \ = __INT_MAX__) {\r\n    long long ret = 1;\r\n    while (n > 0) {\r\n      \
    \  if (n & 1) ret = ret * x % mod;\r\n        x = x * x % mod;\r\n        n >>=\
    \ 1;\r\n    }\r\n    return ret;\r\n}\r\n"
  code: "ll dpow(ll x, ll n, int mod = __INT_MAX__) {\r\n    long long ret = 1;\r\n\
    \    while (n > 0) {\r\n        if (n & 1) ret = ret * x % mod;\r\n        x =\
    \ x * x % mod;\r\n        n >>= 1;\r\n    }\r\n    return ret;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/math/dpow.hpp
  requiredBy: []
  timestamp: '2021-06-18 20:18:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/math/dpow.hpp
layout: document
redirect_from:
- /library/snippet/at/math/dpow.hpp
- /library/snippet/at/math/dpow.hpp.html
title: snippet/at/math/dpow.hpp
---
