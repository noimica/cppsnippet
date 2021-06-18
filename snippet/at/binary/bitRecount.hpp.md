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
  bundledCode: "#line 1 \"snippet/at/binary/bitRecount.hpp\"\nnamespace bit{\r\n \
    \   template <class Func>\r\n    void recount(ll n, Func f){\r\n        for(int\
    \ i=0; n>0; ++i, n>>=1){\r\n            if(n&1) f(i);\r\n        }\r\n    }\r\n\
    \    // \u5168\u4F53\u306Ebit\u6570 \u4F55bit\u7ACB\u305F\u305B\u308B\u304B\r\n\
    \    ll start(ll bit, ll n){\r\n        return ((1<<n)-1)<<(bit-n);\r\n    }\r\
    \n    ll next(ll _x){\r\n        constexpr int llbit = __builtin_clzll(1)+1;\r\
    \n        if((1<<__builtin_popcountll(_x))-1 == _x) return 0;\r\n        ll x\
    \ = _x;\r\n        ll r1 = __builtin_ctzll(x);\r\n        if(r1 > 0){ // \u7E70\
    \u308A\u4E0A\u3052\u306E\u5FC5\u8981\u306A\u3057\r\n            ll t = 1ll<<r1;\r\
    \n            return (_x&~t) | (t>>1);\r\n        }\r\n        x >>= r1;\r\n \
    \       ll r2 = __builtin_ctzll(~x);\r\n        x >>= r2;\r\n        ll r3 = __builtin_ctzll(x);\r\
    \n        x >>= r3;\r\n        // \u7E70\u308A\u4E0A\u3052\u306E\u5FC5\u8981\u304C\
    \u3042\u308B\r\n        return ((x^1)<<(r2+r3)) | start(r2+r3, r2+1);\r\n    }\r\
    \n}\n"
  code: "namespace bit{\r\n    template <class Func>\r\n    void recount(ll n, Func\
    \ f){\r\n        for(int i=0; n>0; ++i, n>>=1){\r\n            if(n&1) f(i);\r\
    \n        }\r\n    }\r\n    // \u5168\u4F53\u306Ebit\u6570 \u4F55bit\u7ACB\u305F\
    \u305B\u308B\u304B\r\n    ll start(ll bit, ll n){\r\n        return ((1<<n)-1)<<(bit-n);\r\
    \n    }\r\n    ll next(ll _x){\r\n        constexpr int llbit = __builtin_clzll(1)+1;\r\
    \n        if((1<<__builtin_popcountll(_x))-1 == _x) return 0;\r\n        ll x\
    \ = _x;\r\n        ll r1 = __builtin_ctzll(x);\r\n        if(r1 > 0){ // \u7E70\
    \u308A\u4E0A\u3052\u306E\u5FC5\u8981\u306A\u3057\r\n            ll t = 1ll<<r1;\r\
    \n            return (_x&~t) | (t>>1);\r\n        }\r\n        x >>= r1;\r\n \
    \       ll r2 = __builtin_ctzll(~x);\r\n        x >>= r2;\r\n        ll r3 = __builtin_ctzll(x);\r\
    \n        x >>= r3;\r\n        // \u7E70\u308A\u4E0A\u3052\u306E\u5FC5\u8981\u304C\
    \u3042\u308B\r\n        return ((x^1)<<(r2+r3)) | start(r2+r3, r2+1);\r\n    }\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/binary/bitRecount.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/binary/bitRecount.hpp
layout: document
redirect_from:
- /library/snippet/at/binary/bitRecount.hpp
- /library/snippet/at/binary/bitRecount.hpp.html
title: snippet/at/binary/bitRecount.hpp
---
