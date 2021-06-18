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
  bundledCode: "#line 1 \"snippet/at/math/prime/osa_k.hpp\"\n#pragma region osa_k\r\
    \n// \u7D20\u56E0\u6570\u5206\u89E3\u306B\u524D\u51E6\u7406\u3092\u304B\u3051\u308B\
    \r\n// \u524D\u51E6\u7406 O(NloglogN)\r\n// \u30AF\u30A8\u30EA O(logN)\r\nstruct\
    \ osa_k{\r\n    vec<ll> min_factor;\r\n    osa_k(int N): min_factor(N+1){\r\n\
    \        //2\u4EE5\u4E0A\u306E\u6570\u3092\u4E00\u5EA6\u7D20\u6570\u5019\u88DC\
    \u306B\u5165\u308C\u308B\r\n        for(int i = 0; i <= N; i++) min_factor[i]\
    \ = i;\r\n        //\u305D\u308C\u305E\u308C\u306E\u6570\u306B\u3064\u3044\u3066\
    \u6700\u5C0F\u306E\u7D20\u56E0\u6570\u3092\u6C42\u3081\u308B\r\n        for(int\
    \ i = 2; i*i <= N; i++){\r\n            if(min_factor[i] == i){\r\n          \
    \      for(int j = 2; i*j <= N; j++){\r\n                    if(min_factor[i*j]\
    \ > i){\r\n                        min_factor[i*j] = i;\r\n                  \
    \  }\r\n                }\r\n            }\r\n        }\r\n    }\r\n    vec<P>\
    \ factorize(int N){\r\n        vec<P> res;\r\n        vec<P>::iterator it;\r\n\
    \        int b = -1;\r\n        while(N > 1){\r\n            if(b != min_factor[N]){\r\
    \n                res.push_back({min_factor[N], 0});\r\n                b = min_factor[N];\r\
    \n                it = res.end()-1;\r\n            }\r\n            it->se++;\r\
    \n            N /= min_factor[N];\r\n        }\r\n        return move(res);\r\n\
    \    }\r\n};\r\n#pragma endregion\n"
  code: "#pragma region osa_k\r\n// \u7D20\u56E0\u6570\u5206\u89E3\u306B\u524D\u51E6\
    \u7406\u3092\u304B\u3051\u308B\r\n// \u524D\u51E6\u7406 O(NloglogN)\r\n// \u30AF\
    \u30A8\u30EA O(logN)\r\nstruct osa_k{\r\n    vec<ll> min_factor;\r\n    osa_k(int\
    \ N): min_factor(N+1){\r\n        //2\u4EE5\u4E0A\u306E\u6570\u3092\u4E00\u5EA6\
    \u7D20\u6570\u5019\u88DC\u306B\u5165\u308C\u308B\r\n        for(int i = 0; i <=\
    \ N; i++) min_factor[i] = i;\r\n        //\u305D\u308C\u305E\u308C\u306E\u6570\
    \u306B\u3064\u3044\u3066\u6700\u5C0F\u306E\u7D20\u56E0\u6570\u3092\u6C42\u3081\
    \u308B\r\n        for(int i = 2; i*i <= N; i++){\r\n            if(min_factor[i]\
    \ == i){\r\n                for(int j = 2; i*j <= N; j++){\r\n               \
    \     if(min_factor[i*j] > i){\r\n                        min_factor[i*j] = i;\r\
    \n                    }\r\n                }\r\n            }\r\n        }\r\n\
    \    }\r\n    vec<P> factorize(int N){\r\n        vec<P> res;\r\n        vec<P>::iterator\
    \ it;\r\n        int b = -1;\r\n        while(N > 1){\r\n            if(b != min_factor[N]){\r\
    \n                res.push_back({min_factor[N], 0});\r\n                b = min_factor[N];\r\
    \n                it = res.end()-1;\r\n            }\r\n            it->se++;\r\
    \n            N /= min_factor[N];\r\n        }\r\n        return move(res);\r\n\
    \    }\r\n};\r\n#pragma endregion"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/math/prime/osa_k.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/math/prime/osa_k.hpp
layout: document
redirect_from:
- /library/snippet/at/math/prime/osa_k.hpp
- /library/snippet/at/math/prime/osa_k.hpp.html
title: snippet/at/math/prime/osa_k.hpp
---
