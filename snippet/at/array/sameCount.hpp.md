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
  bundledCode: "#line 1 \"snippet/at/array/sameCount.hpp\"\n// \u91CD\u8907\u3057\u305F\
    \u8981\u7D20\u3092\u30AB\u30A6\u30F3\u30C8\r\n// O(N)\r\ntemplate <class Iterator>\r\
    \numap<typename iterator_traits<Iterator>::value_type, ll>\r\nsameCount(const\
    \ Iterator begin, const Iterator end){\r\n    umap<typename iterator_traits<Iterator>::value_type,\
    \ ll> mp;\r\n    for (auto it = begin; it != end; ++it) ++mp[*it];\r\n    return\
    \ mp;\r\n}\n"
  code: "// \u91CD\u8907\u3057\u305F\u8981\u7D20\u3092\u30AB\u30A6\u30F3\u30C8\r\n\
    // O(N)\r\ntemplate <class Iterator>\r\numap<typename iterator_traits<Iterator>::value_type,\
    \ ll>\r\nsameCount(const Iterator begin, const Iterator end){\r\n    umap<typename\
    \ iterator_traits<Iterator>::value_type, ll> mp;\r\n    for (auto it = begin;\
    \ it != end; ++it) ++mp[*it];\r\n    return mp;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/array/sameCount.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/array/sameCount.hpp
layout: document
redirect_from:
- /library/snippet/at/array/sameCount.hpp
- /library/snippet/at/array/sameCount.hpp.html
title: snippet/at/array/sameCount.hpp
---
