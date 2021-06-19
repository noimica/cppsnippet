---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/isprime.test.cpp
    title: test/math/isprime.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"snippet/at/math/prime/isprime.hpp\"\n#pragma region isprime\r\
    \n// O(log(N)^2) dpow\u304C\u5FC5\u8981\r\n// \u88DC\u52A9\u95A2\u6570\r\nusing\
    \ ull = unsigned long long;\r\nvec<uint> checklist(ull n){\r\n    if(n < 2047)\
    \                return {2};\r\n    if(n < 9080191)             return {31, 73};\r\
    \n    if(n < 4759123141)          return {2, 7, 61};\r\n    if(n < 1122004669633)\
    \       return {2, 13, 23, 1662803};\r\n    if(n < 2152302898747)       return\
    \ {2, 3, 5, 7, 11};\r\n    if(n < 3474749660383)       return {2, 3, 5, 7, 11,\
    \ 13};\r\n    if(n < 341550071728321)     return {2, 3, 5, 7, 11, 13, 17};\r\n\
    \    if(n < 3825123056546413051) return {2, 3, 5, 7, 11, 13, 17, 19, 23};\r\n\
    \    return {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};\r\n}\r\nbool suspect(uint\
    \ a, ull t, ull n){\r\n    ll x = dpow(a, t, n);\r\n    ll n1 = n - 1;\r\n   \
    \ while(t != n1 && x != 1 && x != n1){\r\n        x = x * x % n;\r\n        t\
    \ <<= 1;\r\n    }\r\n    return (t & 1) || x == n1;\r\n}\r\nbool isprime(ull n){\r\
    \n    if(n == 2) return true;\r\n    if(n < 2 || (n & 1) == 0) return false;\r\
    \n    ull d = (n - 1) >> 1;\r\n    d >>= __builtin_ctzll(d);\r\n    // \u30C1\u30A7\
    \u30C3\u30AF\u30EA\u30B9\u30C8\u4F5C\u6210\r\n    for(auto i : checklist(n)){\r\
    \n        if(i >= n) break;\r\n        if(!suspect(i, d, n)){\r\n            return\
    \ false;\r\n        }\r\n    }\r\n    return true;\r\n}\r\n#pragma endregion\r\
    \n"
  code: "#pragma region isprime\r\n// O(log(N)^2) dpow\u304C\u5FC5\u8981\r\n// \u88DC\
    \u52A9\u95A2\u6570\r\nusing ull = unsigned long long;\r\nvec<uint> checklist(ull\
    \ n){\r\n    if(n < 2047)                return {2};\r\n    if(n < 9080191)  \
    \           return {31, 73};\r\n    if(n < 4759123141)          return {2, 7,\
    \ 61};\r\n    if(n < 1122004669633)       return {2, 13, 23, 1662803};\r\n   \
    \ if(n < 2152302898747)       return {2, 3, 5, 7, 11};\r\n    if(n < 3474749660383)\
    \       return {2, 3, 5, 7, 11, 13};\r\n    if(n < 341550071728321)     return\
    \ {2, 3, 5, 7, 11, 13, 17};\r\n    if(n < 3825123056546413051) return {2, 3, 5,\
    \ 7, 11, 13, 17, 19, 23};\r\n    return {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,\
    \ 37};\r\n}\r\nbool suspect(uint a, ull t, ull n){\r\n    ll x = dpow(a, t, n);\r\
    \n    ll n1 = n - 1;\r\n    while(t != n1 && x != 1 && x != n1){\r\n        x\
    \ = x * x % n;\r\n        t <<= 1;\r\n    }\r\n    return (t & 1) || x == n1;\r\
    \n}\r\nbool isprime(ull n){\r\n    if(n == 2) return true;\r\n    if(n < 2 ||\
    \ (n & 1) == 0) return false;\r\n    ull d = (n - 1) >> 1;\r\n    d >>= __builtin_ctzll(d);\r\
    \n    // \u30C1\u30A7\u30C3\u30AF\u30EA\u30B9\u30C8\u4F5C\u6210\r\n    for(auto\
    \ i : checklist(n)){\r\n        if(i >= n) break;\r\n        if(!suspect(i, d,\
    \ n)){\r\n            return false;\r\n        }\r\n    }\r\n    return true;\r\
    \n}\r\n#pragma endregion\r\n"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/math/prime/isprime.hpp
  requiredBy: []
  timestamp: '2021-06-19 19:28:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/isprime.test.cpp
documentation_of: snippet/at/math/prime/isprime.hpp
layout: document
redirect_from:
- /library/snippet/at/math/prime/isprime.hpp
- /library/snippet/at/math/prime/isprime.hpp.html
title: snippet/at/math/prime/isprime.hpp
---
