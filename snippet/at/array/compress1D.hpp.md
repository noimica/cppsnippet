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
  bundledCode: "#line 1 \"snippet/at/array/compress1D.hpp\"\nstruct Compress1D{\r\n\
    \    map<ll, ll> V;\r\n    Compress1D(){\r\n        V[INF] = V[-INF] = 0;\r\n\
    \    }\r\n    void add(ll x, ll val){\r\n        V[x] += val;\r\n    }\r\n   \
    \ // [l, r]\r\n    void addrange(ll l, ll r, ll val){\r\n        add(l, val);\r\
    \n        add(r+1, -val);\r\n    }\r\n    void imos(){\r\n        ll now = 0;\r\
    \n        for(auto &&p : V){\r\n            now += p.se;\r\n            p.se =\
    \ now;\r\n        }\r\n    }\r\n    ll get(ll x){\r\n        return V.lower_bound(x)->second;\r\
    \n    }\r\n};\n"
  code: "struct Compress1D{\r\n    map<ll, ll> V;\r\n    Compress1D(){\r\n       \
    \ V[INF] = V[-INF] = 0;\r\n    }\r\n    void add(ll x, ll val){\r\n        V[x]\
    \ += val;\r\n    }\r\n    // [l, r]\r\n    void addrange(ll l, ll r, ll val){\r\
    \n        add(l, val);\r\n        add(r+1, -val);\r\n    }\r\n    void imos(){\r\
    \n        ll now = 0;\r\n        for(auto &&p : V){\r\n            now += p.se;\r\
    \n            p.se = now;\r\n        }\r\n    }\r\n    ll get(ll x){\r\n     \
    \   return V.lower_bound(x)->second;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/array/compress1D.hpp
  requiredBy: []
  timestamp: '2021-06-19 22:58:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/array/compress1D.hpp
layout: document
redirect_from:
- /library/snippet/at/array/compress1D.hpp
- /library/snippet/at/array/compress1D.hpp.html
title: snippet/at/array/compress1D.hpp
---
