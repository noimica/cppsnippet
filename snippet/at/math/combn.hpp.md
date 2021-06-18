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
  bundledCode: "#line 1 \"snippet/at/math/combn.hpp\"\n#pragma region combn\r\n//\
    \ nCr\u3092\u6C42\u3081\u308B\r\n// \u524D\u51E6\u7406 O(n)\r\n// \u30AF\u30A8\
    \u30EA O(1)\r\ntemplate <class MINT>\r\nstruct combination {\r\n    vector<MINT>\
    \ fact, ifact;\r\n    combination(int n):fact(n+1),ifact(n+1) {\r\n        fact[0]\
    \ = 1;\r\n        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;\r\n    \
    \    ifact[n] = fact[n].inv();\r\n        for (int i = n; i >= 1; --i) ifact[i-1]\
    \ = ifact[i]*i;\r\n    }\r\n    MINT operator()(int n, int k) {\r\n        if\
    \ (k < 0 || k > n) return 0;\r\n        return fact[n]*ifact[k]*ifact[n-k];\r\n\
    \    }\r\n};\r\n#pragma endregion\n"
  code: "#pragma region combn\r\n// nCr\u3092\u6C42\u3081\u308B\r\n// \u524D\u51E6\
    \u7406 O(n)\r\n// \u30AF\u30A8\u30EA O(1)\r\ntemplate <class MINT>\r\nstruct combination\
    \ {\r\n    vector<MINT> fact, ifact;\r\n    combination(int n):fact(n+1),ifact(n+1)\
    \ {\r\n        fact[0] = 1;\r\n        for (int i = 1; i <= n; ++i) fact[i] =\
    \ fact[i-1]*i;\r\n        ifact[n] = fact[n].inv();\r\n        for (int i = n;\
    \ i >= 1; --i) ifact[i-1] = ifact[i]*i;\r\n    }\r\n    MINT operator()(int n,\
    \ int k) {\r\n        if (k < 0 || k > n) return 0;\r\n        return fact[n]*ifact[k]*ifact[n-k];\r\
    \n    }\r\n};\r\n#pragma endregion"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/math/combn.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/math/combn.hpp
layout: document
redirect_from:
- /library/snippet/at/math/combn.hpp
- /library/snippet/at/math/combn.hpp.html
title: snippet/at/math/combn.hpp
---
