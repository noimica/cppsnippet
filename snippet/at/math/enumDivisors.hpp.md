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
  bundledCode: "#line 1 \"snippet/at/math/enumDivisors.hpp\"\n// \u7D04\u6570\u5217\
    \u6319\r\n//O(\u221AN)\r\nvector<ll> enumDivisors(ll N) {\r\n    vector<ll> res1,\
    \ res2;\r\n    for (ll i = 1; i * i <= N; ++i) {\r\n        if (N % i == 0) {\r\
    \n            res1.push_back(i);\r\n            if (N/i != i) res2.push_back(N/i);\r\
    \n        }\r\n    }\r\n    res1.reserve(res1.size()+res2.size());\r\n    copy(res2.rbegin(),\
    \ res2.rend(), back_inserter(res1));\r\n    return res1;\r\n}\n"
  code: "// \u7D04\u6570\u5217\u6319\r\n//O(\u221AN)\r\nvector<ll> enumDivisors(ll\
    \ N) {\r\n    vector<ll> res1, res2;\r\n    for (ll i = 1; i * i <= N; ++i) {\r\
    \n        if (N % i == 0) {\r\n            res1.push_back(i);\r\n            if\
    \ (N/i != i) res2.push_back(N/i);\r\n        }\r\n    }\r\n    res1.reserve(res1.size()+res2.size());\r\
    \n    copy(res2.rbegin(), res2.rend(), back_inserter(res1));\r\n    return res1;\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/math/enumDivisors.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/math/enumDivisors.hpp
layout: document
redirect_from:
- /library/snippet/at/math/enumDivisors.hpp
- /library/snippet/at/math/enumDivisors.hpp.html
title: snippet/at/math/enumDivisors.hpp
---
