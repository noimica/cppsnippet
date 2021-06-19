---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/primeFactorize.test.cpp
    title: test/math/primeFactorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"snippet/at/math/prime/primeFactorize.hpp\"\n// \u7D20\u56E0\
    \u6570\u5206\u89E3\r\n// O(\u221AN)\r\n// \u8907\u6570\u56DE\u884C\u3046\u306A\
    \u3089osa_k\u6CD5\u3082\u691C\u8A0E\r\nvec<P> primeFactorize(ll N) {\r\n    vec<P>\
    \ res;\r\n    for (ll a = 2; a * a <= N; ++a) {\r\n        if (N % a != 0) continue;\r\
    \n        ll ex = 0; // \u6307\u6570\r\n        // \u5272\u308C\u308B\u9650\u308A\
    \u5272\u308A\u7D9A\u3051\u308B\r\n        while (N % a == 0) {\r\n           \
    \ ++ex;\r\n            N /= a;\r\n        }\r\n        res.push_back({a, ex});\r\
    \n    }\r\n    // \u6700\u5F8C\u306B\u6B8B\u3063\u305F\u6570\u306B\u3064\u3044\
    \u3066\r\n    if (N != 1) res.push_back({N, 1});\r\n    return res;\r\n}\n"
  code: "// \u7D20\u56E0\u6570\u5206\u89E3\r\n// O(\u221AN)\r\n// \u8907\u6570\u56DE\
    \u884C\u3046\u306A\u3089osa_k\u6CD5\u3082\u691C\u8A0E\r\nvec<P> primeFactorize(ll\
    \ N) {\r\n    vec<P> res;\r\n    for (ll a = 2; a * a <= N; ++a) {\r\n       \
    \ if (N % a != 0) continue;\r\n        ll ex = 0; // \u6307\u6570\r\n        //\
    \ \u5272\u308C\u308B\u9650\u308A\u5272\u308A\u7D9A\u3051\u308B\r\n        while\
    \ (N % a == 0) {\r\n            ++ex;\r\n            N /= a;\r\n        }\r\n\
    \        res.push_back({a, ex});\r\n    }\r\n    // \u6700\u5F8C\u306B\u6B8B\u3063\
    \u305F\u6570\u306B\u3064\u3044\u3066\r\n    if (N != 1) res.push_back({N, 1});\r\
    \n    return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/math/prime/primeFactorize.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/primeFactorize.test.cpp
documentation_of: snippet/at/math/prime/primeFactorize.hpp
layout: document
redirect_from:
- /library/snippet/at/math/prime/primeFactorize.hpp
- /library/snippet/at/math/prime/primeFactorize.hpp.html
title: snippet/at/math/prime/primeFactorize.hpp
---
