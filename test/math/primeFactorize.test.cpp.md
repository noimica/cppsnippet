---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snippet/at/header/header.hpp
    title: snippet/at/header/header.hpp
  - icon: ':heavy_check_mark:'
    path: snippet/at/math/prime/primeFactorize.hpp
    title: snippet/at/math/prime/primeFactorize.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"test/math/primeFactorize.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\r\n\r\n#line\
    \ 1 \"snippet/at/header/header.hpp\"\n#pragma region Macros\r\n#include <bits/stdc++.h>\r\
    \n#if defined(LOCAL) || defined(ONLINE_JUDGE) || defined(_DEBUG)\r\n#include <atcoder/all>\r\
    \n#endif\r\nusing namespace std;\r\n#define REP(i, n) for(int i=0, i##_len=(n);\
    \ i<i##_len; ++i)\r\n#define REPR(i, n) for(int i=(n); i>=0; --i)\r\n#define FOR(i,\
    \ n, m) for(int i=(m), i##_len=(n); i<i##_len; ++i)\r\n#define EACH(i, v) for(const\
    \ auto& i : v)\r\n#define ALL(x) (x).begin(),(x).end()\r\n#define ALLR(x) (x).rbegin(),(x).rend()\r\
    \ntemplate<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; }\
    \ return 0; }\r\ntemplate<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b;\
    \ return 1; } return 0; }\r\ntemplate<class T>using vec = vector<T>;\r\ntemplate<class\
    \ T, class U>using umap = unordered_map<T, U>;\r\ntemplate<class T>using uset\
    \ = unordered_set<T>;\r\nusing ll = long long;\r\nusing ld = long double;\r\n\
    using P = pair<ll, ll>;\r\n//using T = tuple<ll, ll, ll>;\r\nusing vl = vec<ll>;\r\
    \n#define fi first\r\n#define se second\r\n#define el endl\r\nconstexpr ll INF\
    \ = numeric_limits<ll>::max()/2-1;\r\n#pragma endregion\r\n\r\n#pragma region\
    \ IOMacros\r\ntemplate<class T>\r\nistream &operator>>(istream &stream, vec<T>&\
    \ o){REP(i, o.size())stream >> o[i];return stream;}\r\ntemplate<class T>\r\nostream\
    \ &operator<<(ostream &stream, vec<T>& objs){REP(i, objs.size())stream << objs[i]\
    \ << \" \";stream << el;return stream;}\r\n\r\n#define I(T, ...) ;T __VA_ARGS__;__i(__VA_ARGS__);\r\
    \nvoid __i() {}\r\ntemplate<class T, class... Ts> void __i(T&& o, Ts&&... args){cin\
    \ >> o;__i(forward<Ts>(args)...);}\r\n\r\n#ifdef LOCAL\r\nvoid O() {cerr << el;}\r\
    \ntemplate<class T, class... Ts> void O(T&& o, Ts&&... args){cerr << o << \" \"\
    ;O(forward<Ts>(args)...);}\r\n#else\r\ntemplate<class T, class... Ts> void O(T&&\
    \ o, Ts&&... args){};\r\n#endif\r\n#pragma endregion\r\n#line 1 \"snippet/at/math/prime/primeFactorize.hpp\"\
    \n// \u7D20\u56E0\u6570\u5206\u89E3\r\n// O(\u221AN)\r\n// \u8907\u6570\u56DE\u884C\
    \u3046\u306A\u3089osa_k\u6CD5\u3082\u691C\u8A0E\r\nvec<P> primeFactorize(ll N)\
    \ {\r\n    vec<P> res;\r\n    for (ll a = 2; a * a <= N; ++a) {\r\n        if\
    \ (N % a != 0) continue;\r\n        ll ex = 0; // \u6307\u6570\r\n        // \u5272\
    \u308C\u308B\u9650\u308A\u5272\u308A\u7D9A\u3051\u308B\r\n        while (N % a\
    \ == 0) {\r\n            ++ex;\r\n            N /= a;\r\n        }\r\n       \
    \ res.push_back({a, ex});\r\n    }\r\n    // \u6700\u5F8C\u306B\u6B8B\u3063\u305F\
    \u6570\u306B\u3064\u3044\u3066\r\n    if (N != 1) res.push_back({N, 1});\r\n \
    \   return res;\r\n}\n#line 5 \"test/math/primeFactorize.test.cpp\"\n\r\nint main(){\r\
    \n    I(ll, N);\r\n    auto pf = primeFactorize(N);\r\n    cout << N << \":\"\
    ;\r\n    EACH(v, pf){\r\n        REP(i, v.se){\r\n            cout << \" \" <<\
    \ v.fi;\r\n        }\r\n    }\r\n    cout << el;\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \r\n\r\n#include \"./snippet/at/header/header.hpp\"\r\n#include \"./snippet/at/math/prime/primeFactorize.hpp\"\
    \r\n\r\nint main(){\r\n    I(ll, N);\r\n    auto pf = primeFactorize(N);\r\n \
    \   cout << N << \":\";\r\n    EACH(v, pf){\r\n        REP(i, v.se){\r\n     \
    \       cout << \" \" << v.fi;\r\n        }\r\n    }\r\n    cout << el;\r\n  \
    \  return 0;\r\n}"
  dependsOn:
  - snippet/at/header/header.hpp
  - snippet/at/math/prime/primeFactorize.hpp
  isVerificationFile: true
  path: test/math/primeFactorize.test.cpp
  requiredBy: []
  timestamp: '2021-06-19 19:28:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/primeFactorize.test.cpp
layout: document
redirect_from:
- /verify/test/math/primeFactorize.test.cpp
- /verify/test/math/primeFactorize.test.cpp.html
title: test/math/primeFactorize.test.cpp
---
