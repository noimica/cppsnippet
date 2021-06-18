---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: snippet/at/graph/graph.hpp
    title: snippet/at/graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: snippet/at/graph/warshall_floyd.hpp
    title: snippet/at/graph/warshall_floyd.hpp
  - icon: ':question:'
    path: snippet/at/header/header.hpp
    title: snippet/at/header/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
  bundledCode: "#line 1 \"test/graph/warshall_floyd.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C\"\r\n\r\n#line\
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
    \ o, Ts&&... args){};\r\n#endif\r\n#pragma endregion\r\n#line 1 \"snippet/at/graph/graph.hpp\"\
    \n#pragma region graph\r\nstruct edge{\r\n    ll from, to, cost;\r\n    bool operator<(const\
    \ edge& r) const{return cost<r.cost;}\r\n    bool operator>(const edge& r) const{return\
    \ cost>r.cost;}\r\n};\r\nstruct graph{\r\n    ll V;\r\n    vector<vector<edge>\
    \ > G;\r\n    graph(ll n){\r\n        init(n);\r\n    }\r\n    void init(ll n){\r\
    \n        V = n;\r\n        G.resize(V);\r\n    }\r\n    // \u7121\u5411\u30B0\
    \u30E9\u30D5\r\n    void add_edge(ll s, ll t, ll cost = 1){\r\n        add_diedge(s,\
    \ t, cost);\r\n        add_diedge(t, s, cost);\r\n    }\r\n    // \u6709\u5411\
    \u30B0\u30E9\u30D5\r\n    void add_diedge(ll s, ll t, ll cost = 1){\r\n      \
    \  if(s < 0 || t < 0 || s >= V || t >= V) return;\r\n        G[s].push_back({s,\
    \ t, cost});\r\n    }\r\n    auto pos2d(ll height, ll width){\r\n        return\
    \ [height, width](ll y, ll x){\r\n            return \r\n                (y <\
    \ 0 || y >= height || x < 0 || x >= width)\r\n                ? -1\r\n       \
    \         : y*width + x;\r\n        };\r\n    }\r\n};\r\n#pragma endregion\n#line\
    \ 1 \"snippet/at/graph/warshall_floyd.hpp\"\n#pragma region warshall_floyd\r\n\
    // O(|V|^3)\r\npair<bool, vector<vector<ll>>> warshall_floyd(const vector<vector<ll>>\
    \ &_dist){\r\n    int V = _dist.size();\r\n    vector<vector<ll>> dist(_dist);\r\
    \n    REP(k, V) {\r\n        REP(i, V) {\r\n            REP(j, V) {\r\n      \
    \          if(dist[i][k] == INF || dist[k][j] == INF) continue;\r\n          \
    \      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);\r\n            }\r\
    \n        }\r\n    }\r\n    bool is_negative_cycle = false;\r\n    REP(i, V){\r\
    \n        if(dist[i][i] < 0){\r\n            is_negative_cycle = true;break;\r\
    \n        }\r\n    }\r\n    return {is_negative_cycle, dist};\r\n}\r\npair<bool,\
    \ vector<vector<ll>>> warshall_floyd(const graph& g) {\r\n    int V = g.V;\r\n\
    \    vector<vector<ll>> dist(V, vector<ll>(V, INF));\r\n    REP(i, V){\r\n   \
    \     dist[i][i] = 0;\r\n        for(auto e : g.G[i]){\r\n            dist[i][e.to]\
    \ = e.cost;\r\n        }\r\n    }\r\n    return warshall_floyd(dist);\r\n}\r\n\
    #pragma endregion\n#line 6 \"test/graph/warshall_floyd.test.cpp\"\n\r\nint main(){\r\
    \n    I(ll, V, E);\r\n    graph g(V);\r\n    REP(i, E){\r\n        I(ll, s, t,\
    \ d);\r\n        g.add_diedge(s, t, d);\r\n    }\r\n\r\n    auto [nc, d] = warshall_floyd(g);\r\
    \n    if(nc){\r\n        cout << \"NEGATIVE CYCLE\" << el;\r\n        return 0;\r\
    \n    }\r\n    REP(i, V){\r\n        REP(j, V){\r\n            if(j > 0){\r\n\
    \                cout << \" \";\r\n            }\r\n            if(d[i][j] !=\
    \ INF){\r\n                cout << d[i][j];\r\n            }else{\r\n        \
    \        cout << \"INF\";\r\n            }\r\n        }\r\n        cout << el;\r\
    \n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C\"\
    \r\n\r\n#include \"./snippet/at/header/header.hpp\"\r\n#include \"./snippet/at/graph/graph.hpp\"\
    \r\n#include \"./snippet/at/graph/warshall_floyd.hpp\"\r\n\r\nint main(){\r\n\
    \    I(ll, V, E);\r\n    graph g(V);\r\n    REP(i, E){\r\n        I(ll, s, t,\
    \ d);\r\n        g.add_diedge(s, t, d);\r\n    }\r\n\r\n    auto [nc, d] = warshall_floyd(g);\r\
    \n    if(nc){\r\n        cout << \"NEGATIVE CYCLE\" << el;\r\n        return 0;\r\
    \n    }\r\n    REP(i, V){\r\n        REP(j, V){\r\n            if(j > 0){\r\n\
    \                cout << \" \";\r\n            }\r\n            if(d[i][j] !=\
    \ INF){\r\n                cout << d[i][j];\r\n            }else{\r\n        \
    \        cout << \"INF\";\r\n            }\r\n        }\r\n        cout << el;\r\
    \n    }\r\n    return 0;\r\n}"
  dependsOn:
  - snippet/at/header/header.hpp
  - snippet/at/graph/graph.hpp
  - snippet/at/graph/warshall_floyd.hpp
  isVerificationFile: true
  path: test/graph/warshall_floyd.test.cpp
  requiredBy: []
  timestamp: '2021-06-18 19:34:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/warshall_floyd.test.cpp
layout: document
redirect_from:
- /verify/test/graph/warshall_floyd.test.cpp
- /verify/test/graph/warshall_floyd.test.cpp.html
title: test/graph/warshall_floyd.test.cpp
---
