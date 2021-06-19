---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/SCC.test.cpp
    title: test/graph/SCC.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/TravelingSalesmanProblem.test.cpp
    title: test/graph/TravelingSalesmanProblem.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/bellmanFord.test.cpp
    title: test/graph/bellmanFord.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal.test.cpp
    title: test/graph/kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/max_flow.test.cpp
    title: test/graph/max_flow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/prim.test.cpp
    title: test/graph/prim.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/warshallFloyd.test.cpp
    title: test/graph/warshallFloyd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/dpow.test.cpp
    title: test/math/dpow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/isprime.test.cpp
    title: test/math/isprime.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/primeFactorize.test.cpp
    title: test/math/primeFactorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/struct/LazySegmentTree/RMQ_RAQ.test.cpp
    title: test/struct/LazySegmentTree/RMQ_RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/struct/LazySegmentTree/RMQ_RUQ.test.cpp
    title: test/struct/LazySegmentTree/RMQ_RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/struct/LazySegmentTree/RSQ_RAQ.test.cpp
    title: test/struct/LazySegmentTree/RSQ_RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/struct/LazySegmentTree/RSQ_RUQ.test.cpp
    title: test/struct/LazySegmentTree/RSQ_RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/struct/UnionFind.test.cpp
    title: test/struct/UnionFind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/struct/modint_pow.test.cpp
    title: test/struct/modint_pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"snippet/at/header/header.hpp\"\n#pragma region Macros\r\n\
    #include <bits/stdc++.h>\r\n#if defined(LOCAL) || defined(ONLINE_JUDGE) || defined(_DEBUG)\r\
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
    #pragma endregion\r\n"
  code: "#pragma region Macros\r\n#include <bits/stdc++.h>\r\n#if defined(LOCAL) ||\
    \ defined(ONLINE_JUDGE) || defined(_DEBUG)\r\n#include <atcoder/all>\r\n#endif\r\
    \nusing namespace std;\r\n#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len;\
    \ ++i)\r\n#define REPR(i, n) for(int i=(n); i>=0; --i)\r\n#define FOR(i, n, m)\
    \ for(int i=(m), i##_len=(n); i<i##_len; ++i)\r\n#define EACH(i, v) for(const\
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
    \ o, Ts&&... args){};\r\n#endif\r\n#pragma endregion\r\n"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/header/header.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/struct/modint_pow.test.cpp
  - test/struct/LazySegmentTree/RMQ_RAQ.test.cpp
  - test/struct/LazySegmentTree/RSQ_RUQ.test.cpp
  - test/struct/LazySegmentTree/RSQ_RAQ.test.cpp
  - test/struct/LazySegmentTree/RMQ_RUQ.test.cpp
  - test/struct/UnionFind.test.cpp
  - test/graph/TravelingSalesmanProblem.test.cpp
  - test/graph/dijkstra.test.cpp
  - test/graph/bellmanFord.test.cpp
  - test/graph/prim.test.cpp
  - test/graph/SCC.test.cpp
  - test/graph/max_flow.test.cpp
  - test/graph/warshallFloyd.test.cpp
  - test/graph/kruskal.test.cpp
  - test/math/primeFactorize.test.cpp
  - test/math/dpow.test.cpp
  - test/math/isprime.test.cpp
documentation_of: snippet/at/header/header.hpp
layout: document
redirect_from:
- /library/snippet/at/header/header.hpp
- /library/snippet/at/header/header.hpp.html
title: snippet/at/header/header.hpp
---
