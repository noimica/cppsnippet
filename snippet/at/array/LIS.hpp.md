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
  bundledCode: "#line 1 \"snippet/at/array/LIS.hpp\"\n// \u6700\u9577\u90E8\u5206\u5897\
    \u52A0\u5217 O(NlogN)\r\ntemplate <class T>\r\nvec<P> LIS(const vector<T>& A){\r\
    \n    vl dp;\r\n    vec<P> X(A.size());\r\n    REP(i, A.size()){\r\n        auto\
    \ p = lower_bound(ALL(dp), A[i]);\r\n        if(p != dp.end()){\r\n          \
    \  *p = A[i];\r\n        }else{\r\n            dp.push_back(A[i]);\r\n       \
    \ }\r\n        X[i] = {dp.size(), dp[dp.size()-1]};\r\n    }\r\n    return X;\r\
    \n}\n"
  code: "// \u6700\u9577\u90E8\u5206\u5897\u52A0\u5217 O(NlogN)\r\ntemplate <class\
    \ T>\r\nvec<P> LIS(const vector<T>& A){\r\n    vl dp;\r\n    vec<P> X(A.size());\r\
    \n    REP(i, A.size()){\r\n        auto p = lower_bound(ALL(dp), A[i]);\r\n  \
    \      if(p != dp.end()){\r\n            *p = A[i];\r\n        }else{\r\n    \
    \        dp.push_back(A[i]);\r\n        }\r\n        X[i] = {dp.size(), dp[dp.size()-1]};\r\
    \n    }\r\n    return X;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/array/LIS.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/array/LIS.hpp
layout: document
redirect_from:
- /library/snippet/at/array/LIS.hpp
- /library/snippet/at/array/LIS.hpp.html
title: snippet/at/array/LIS.hpp
---
