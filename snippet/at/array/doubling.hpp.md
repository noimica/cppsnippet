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
  bundledCode: "#line 1 \"snippet/at/array/doubling.hpp\"\ntemplate <class T>\r\n\
    struct Doubling\r\n{\r\n  const int LOG;\r\n  vector< vector< int > > table;\r\
    \n  \r\n  Doubling(int sz, int64_t lim_t) : LOG(64 - __builtin_clzll(lim_t))\r\
    \n  {\r\n    table.assign(LOG, vector< int >(sz, -1));\r\n  }\r\n\r\n  void set_next(int\
    \ k, int x)\r\n  {\r\n    table[0][k] = x;\r\n  }\r\n\r\n  void build()\r\n  {\r\
    \n    for(int k = 0; k + 1 < LOG; k++) {\r\n      for(int i = 0; i < table[k].size();\
    \ i++) {\r\n        if(table[k][i] == -1) table[k + 1][i] = -1;\r\n        else\
    \ table[k + 1][i] = table[k][table[k][i]];\r\n      }\r\n    }\r\n  }\r\n\r\n\
    \  int query(int k, int64_t t)\r\n  {\r\n    for(int i = LOG - 1; i >= 0; i--)\
    \ {\r\n      if((t >> i) & 1) k = table[i][k];\r\n    }\r\n    return k;\r\n \
    \ }\r\n};\n"
  code: "template <class T>\r\nstruct Doubling\r\n{\r\n  const int LOG;\r\n  vector<\
    \ vector< int > > table;\r\n  \r\n  Doubling(int sz, int64_t lim_t) : LOG(64 -\
    \ __builtin_clzll(lim_t))\r\n  {\r\n    table.assign(LOG, vector< int >(sz, -1));\r\
    \n  }\r\n\r\n  void set_next(int k, int x)\r\n  {\r\n    table[0][k] = x;\r\n\
    \  }\r\n\r\n  void build()\r\n  {\r\n    for(int k = 0; k + 1 < LOG; k++) {\r\n\
    \      for(int i = 0; i < table[k].size(); i++) {\r\n        if(table[k][i] ==\
    \ -1) table[k + 1][i] = -1;\r\n        else table[k + 1][i] = table[k][table[k][i]];\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  int query(int k, int64_t t)\r\n  {\r\n    for(int\
    \ i = LOG - 1; i >= 0; i--) {\r\n      if((t >> i) & 1) k = table[i][k];\r\n \
    \   }\r\n    return k;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/array/doubling.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/array/doubling.hpp
layout: document
redirect_from:
- /library/snippet/at/array/doubling.hpp
- /library/snippet/at/array/doubling.hpp.html
title: snippet/at/array/doubling.hpp
---
