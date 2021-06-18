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
  bundledCode: "#line 1 \"snippet/at/math/combk.hpp\"\n#pragma region combk\r\n//\
    \ nCr\u3092\u6C42\u3081\u308B\r\n// \u524D\u51E6\u7406 O(k)\r\n// \u30AF\u30A8\
    \u30EA O(k)\r\ntemplate <class MINT>\r\nstruct comb {\r\n    vector<MINT> fact,\
    \ ifact;\r\n    comb(int k):fact(k+1),ifact(k+1) {\r\n        fact[0] = 1;\r\n\
    \        for (int i = 1; i <= k; ++i) fact[i] = fact[i-1]*i;\r\n        ifact[k]\
    \ = fact[k].inv();\r\n        for (int i = k; i >= 1; --i) ifact[i-1] = ifact[i]*i;\r\
    \n    }\r\n    MINT operator()(int n, int k) {\r\n        if (k < 0 || k > n)\
    \ return 0;\r\n        MINT ans(1);\r\n        for(int i = n; i >= n - k + 1;\
    \ --i) ans *= i;\r\n        return ans * ifact[k];\r\n    }\r\n};\r\n#pragma endregion\n"
  code: "#pragma region combk\r\n// nCr\u3092\u6C42\u3081\u308B\r\n// \u524D\u51E6\
    \u7406 O(k)\r\n// \u30AF\u30A8\u30EA O(k)\r\ntemplate <class MINT>\r\nstruct comb\
    \ {\r\n    vector<MINT> fact, ifact;\r\n    comb(int k):fact(k+1),ifact(k+1) {\r\
    \n        fact[0] = 1;\r\n        for (int i = 1; i <= k; ++i) fact[i] = fact[i-1]*i;\r\
    \n        ifact[k] = fact[k].inv();\r\n        for (int i = k; i >= 1; --i) ifact[i-1]\
    \ = ifact[i]*i;\r\n    }\r\n    MINT operator()(int n, int k) {\r\n        if\
    \ (k < 0 || k > n) return 0;\r\n        MINT ans(1);\r\n        for(int i = n;\
    \ i >= n - k + 1; --i) ans *= i;\r\n        return ans * ifact[k];\r\n    }\r\n\
    };\r\n#pragma endregion"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/math/combk.hpp
  requiredBy: []
  timestamp: '2021-06-18 20:18:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/math/combk.hpp
layout: document
redirect_from:
- /library/snippet/at/math/combk.hpp
- /library/snippet/at/math/combk.hpp.html
title: snippet/at/math/combk.hpp
---