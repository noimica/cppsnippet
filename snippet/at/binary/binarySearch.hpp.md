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
  bundledCode: "#line 1 \"snippet/at/binary/binarySearch.hpp\"\n// x\u2208[l, r] |\
    \ f(x) = true \u3068\u306A\u308B\u6700\u5927\u306Ex\u3092\u8FD4\u3059\r\ntemplate\
    \ <class Func>\r\nll BinarySearch(ll l, ll r, Func f){\r\n    while(l < r){\r\n\
    \        const ll m = (l+r+1)/2;\r\n        if(f(m)) l = m;\r\n        else  \
    \   r = m-1;\r\n    }\r\n    return l;\r\n}\n"
  code: "// x\u2208[l, r] | f(x) = true \u3068\u306A\u308B\u6700\u5927\u306Ex\u3092\
    \u8FD4\u3059\r\ntemplate <class Func>\r\nll BinarySearch(ll l, ll r, Func f){\r\
    \n    while(l < r){\r\n        const ll m = (l+r+1)/2;\r\n        if(f(m)) l =\
    \ m;\r\n        else     r = m-1;\r\n    }\r\n    return l;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/binary/binarySearch.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/binary/binarySearch.hpp
layout: document
redirect_from:
- /library/snippet/at/binary/binarySearch.hpp
- /library/snippet/at/binary/binarySearch.hpp.html
title: snippet/at/binary/binarySearch.hpp
---
