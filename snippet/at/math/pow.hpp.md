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
  bundledCode: "#line 1 \"snippet/at/math/pow.hpp\"\nll dpow(ll x, ll n, int mod =\
    \ __INT_MAX__) {\r\n    long long ret = 1;\r\n    while (n > 0) {\r\n        if\
    \ (n & 1) ret = ret * x % mod;\r\n        x = x * x % mod;\r\n        n >>= 1;\r\
    \n    }\r\n    return ret;\r\n}\r\n"
  code: "ll dpow(ll x, ll n, int mod = __INT_MAX__) {\r\n    long long ret = 1;\r\n\
    \    while (n > 0) {\r\n        if (n & 1) ret = ret * x % mod;\r\n        x =\
    \ x * x % mod;\r\n        n >>= 1;\r\n    }\r\n    return ret;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/math/pow.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/math/pow.hpp
layout: document
redirect_from:
- /library/snippet/at/math/pow.hpp
- /library/snippet/at/math/pow.hpp.html
title: snippet/at/math/pow.hpp
---
