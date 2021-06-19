---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snippet/at/header/header.hpp
    title: snippet/at/header/header.hpp
  - icon: ':heavy_check_mark:'
    path: snippet/at/math/dpow.hpp
    title: snippet/at/math/dpow.hpp
  - icon: ':heavy_check_mark:'
    path: snippet/at/math/prime/isprime.hpp
    title: snippet/at/math/prime/isprime.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
  bundledCode: "#line 1 \"test/math/isprime.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \r\n\r\n#line 1 \"snippet/at/header/header.hpp\"\n#pragma region Macros\r\n#include\
    \ <bits/stdc++.h>\r\n#if defined(LOCAL) || defined(ONLINE_JUDGE) || defined(_DEBUG)\r\
    \n#include <atcoder/all>\r\n#endif\r\nusing namespace std;\r\n#define REP(i, n)\
    \ for(int i=0, i##_len=(n); i<i##_len; ++i)\r\n#define REPR(i, n) for(int i=(n);\
    \ i>=0; --i)\r\n#define FOR(i, n, m) for(int i=(m), i##_len=(n); i<i##_len; ++i)\r\
    \n#define EACH(i, v) for(const auto& i : v)\r\n#define ALL(x) (x).begin(),(x).end()\r\
    \n#define ALLR(x) (x).rbegin(),(x).rend()\r\ntemplate<class T>bool chmax(T &a,\
    \ const T &b) { if (a<b) { a=b; return 1; } return 0; }\r\ntemplate<class T>bool\
    \ chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }\r\ntemplate<class\
    \ T>using vec = vector<T>;\r\ntemplate<class T, class U>using umap = unordered_map<T,\
    \ U>;\r\ntemplate<class T>using uset = unordered_set<T>;\r\nusing ll = long long;\r\
    \nusing ld = long double;\r\nusing P = pair<ll, ll>;\r\n//using T = tuple<ll,\
    \ ll, ll>;\r\nusing vl = vec<ll>;\r\n#define fi first\r\n#define se second\r\n\
    #define el endl\r\nconstexpr ll INF = numeric_limits<ll>::max()/2-1;\r\n#pragma\
    \ endregion\r\n\r\n#pragma region IOMacros\r\ntemplate<class T>\r\nistream &operator>>(istream\
    \ &stream, vec<T>& o){REP(i, o.size())stream >> o[i];return stream;}\r\ntemplate<class\
    \ T>\r\nostream &operator<<(ostream &stream, vec<T>& objs){REP(i, objs.size())stream\
    \ << objs[i] << \" \";stream << el;return stream;}\r\n\r\n#define I(T, ...) ;T\
    \ __VA_ARGS__;__i(__VA_ARGS__);\r\nvoid __i() {}\r\ntemplate<class T, class...\
    \ Ts> void __i(T&& o, Ts&&... args){cin >> o;__i(forward<Ts>(args)...);}\r\n\r\
    \n#ifdef LOCAL\r\nvoid O() {cerr << el;}\r\ntemplate<class T, class... Ts> void\
    \ O(T&& o, Ts&&... args){cerr << o << \" \";O(forward<Ts>(args)...);}\r\n#else\r\
    \ntemplate<class T, class... Ts> void O(T&& o, Ts&&... args){};\r\n#endif\r\n\
    #pragma endregion\r\n#line 1 \"snippet/at/math/dpow.hpp\"\nll dpow(ll x, ll n,\
    \ int mod = __INT_MAX__) {\r\n    long long ret = 1;\r\n    while (n > 0) {\r\n\
    \        if (n & 1) ret = ret * x % mod;\r\n        x = x * x % mod;\r\n     \
    \   n >>= 1;\r\n    }\r\n    return ret;\r\n}\r\n#line 1 \"snippet/at/math/prime/isprime.hpp\"\
    \n#pragma region isprime\r\n// O(log(N)^2) dpow\u304C\u5FC5\u8981\r\n// \u88DC\
    \u52A9\u95A2\u6570\r\nusing ull = unsigned long long;\r\nvec<uint> checklist(ull\
    \ n){\r\n    if(n < 2047)                return {2};\r\n    if(n < 9080191)  \
    \           return {31, 73};\r\n    if(n < 4759123141)          return {2, 7,\
    \ 61};\r\n    if(n < 1122004669633)       return {2, 13, 23, 1662803};\r\n   \
    \ if(n < 2152302898747)       return {2, 3, 5, 7, 11};\r\n    if(n < 3474749660383)\
    \       return {2, 3, 5, 7, 11, 13};\r\n    if(n < 341550071728321)     return\
    \ {2, 3, 5, 7, 11, 13, 17};\r\n    if(n < 3825123056546413051) return {2, 3, 5,\
    \ 7, 11, 13, 17, 19, 23};\r\n    return {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,\
    \ 37};\r\n}\r\nbool suspect(uint a, ull t, ull n){\r\n    ll x = dpow(a, t, n);\r\
    \n    ll n1 = n - 1;\r\n    while(t != n1 && x != 1 && x != n1){\r\n        x\
    \ = x * x % n;\r\n        t <<= 1;\r\n    }\r\n    return (t & 1) || x == n1;\r\
    \n}\r\nbool isprime(ull n){\r\n    if(n == 2) return true;\r\n    if(n < 2 ||\
    \ (n & 1) == 0) return false;\r\n    ull d = (n - 1) >> 1;\r\n    d >>= __builtin_ctzll(d);\r\
    \n    // \u30C1\u30A7\u30C3\u30AF\u30EA\u30B9\u30C8\u4F5C\u6210\r\n    for(auto\
    \ i : checklist(n)){\r\n        if(i >= n) break;\r\n        if(!suspect(i, d,\
    \ n)){\r\n            return false;\r\n        }\r\n    }\r\n    return true;\r\
    \n}\r\n#pragma endregion\r\n#line 6 \"test/math/isprime.test.cpp\"\n\r\nint main(){\r\
    \n    I(ll, N);\r\n    ll cnt = 0;\r\n    REP(i, N){\r\n        I(ll, M);\r\n\
    \        if(isprime(M)){\r\n            cnt++;\r\n        }\r\n    }\r\n    cout\
    \ << cnt << el;\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \r\n\r\n#include \"./snippet/at/header/header.hpp\"\r\n#include \"./snippet/at/math/dpow.hpp\"\
    \r\n#include \"./snippet/at/math/prime/isprime.hpp\"\r\n\r\nint main(){\r\n  \
    \  I(ll, N);\r\n    ll cnt = 0;\r\n    REP(i, N){\r\n        I(ll, M);\r\n   \
    \     if(isprime(M)){\r\n            cnt++;\r\n        }\r\n    }\r\n    cout\
    \ << cnt << el;\r\n    return 0;\r\n}"
  dependsOn:
  - snippet/at/header/header.hpp
  - snippet/at/math/dpow.hpp
  - snippet/at/math/prime/isprime.hpp
  isVerificationFile: true
  path: test/math/isprime.test.cpp
  requiredBy: []
  timestamp: '2021-06-19 19:28:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/isprime.test.cpp
layout: document
redirect_from:
- /verify/test/math/isprime.test.cpp
- /verify/test/math/isprime.test.cpp.html
title: test/math/isprime.test.cpp
---
