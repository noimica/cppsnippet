---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: snippet/at/graph/Tsort.hpp
    title: snippet/at/graph/Tsort.hpp
  - icon: ':question:'
    path: snippet/at/graph/graph.hpp
    title: snippet/at/graph/graph.hpp
  - icon: ':question:'
    path: snippet/at/header/header.hpp
    title: snippet/at/header/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
  bundledCode: "#line 1 \"test/graph/Tsort.test.cpp\"\n// \u7B54\u3048\u304C\u8907\
    \u6570\u3042\u308B\u304C\u3001\u30ED\u30FC\u30AB\u30EB\u30B8\u30E3\u30C3\u30B8\
    \u304C\u5BFE\u5FDC\u3057\u3066\u3044\u306A\u3044\u306E\u3067NG\r\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B\"\r\n\r\n\
    #line 1 \"snippet/at/header/header.hpp\"\n#pragma region Macros\r\n#include <bits/stdc++.h>\r\
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
    \ 1 \"snippet/at/graph/Tsort.hpp\"\n// \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
    \u30FC\u30C8 O(V+E)\r\nvl Tsort(const graph &g) {  // bfs\r\n    vl ans;\r\n \
    \   int n = (int)g.V;\r\n    vl ind(n);            // ind[i]: \u9802\u70B9i\u306B\
    \u5165\u308B\u8FBA\u306E\u6570(\u6B21\u6570)\r\n    for (int i = 0; i < n; i++)\
    \ {  // \u6B21\u6570\u3092\u6570\u3048\u3066\u304A\u304F\r\n        for (auto\
    \ e : g.G[i]) {\r\n            ind[e.to]++;\r\n        }\r\n    }\r\n    queue<int>\
    \ que;\r\n    for (int i = 0; i < n; i++) {  // \u6B21\u6570\u304C0\u306E\u70B9\
    \u3092\u30AD\u30E5\u30FC\u306B\u5165\u308C\u308B\r\n        if (ind[i] == 0) {\r\
    \n            que.push(i);\r\n        }\r\n    }\r\n    while (!que.empty()) {\
    \  // \u5E45\u512A\u5148\u63A2\u7D22\r\n        int now = que.front();\r\n   \
    \     ans.push_back(now);\r\n        que.pop();\r\n        for (auto e : g.G[now])\
    \ {\r\n            ind[e.to]--;\r\n            if (ind[e.to] == 0) {\r\n     \
    \           que.push(e.to);\r\n            }\r\n        }\r\n    }\r\n    return\
    \ ans;\r\n}\n#line 7 \"test/graph/Tsort.test.cpp\"\n\r\nint main(){\r\n    I(ll,\
    \ V, E);\r\n    graph g(V);\r\n    REP(i, E){\r\n        I(ll, s, t);\r\n    \
    \    g.add_diedge(s, t);\r\n    }\r\n\r\n    auto vs = Tsort(g);\r\n    REP(i,\
    \ V){\r\n        cout << vs[i] << el;\r\n    }\r\n    return 0;\r\n}\n"
  code: "// \u7B54\u3048\u304C\u8907\u6570\u3042\u308B\u304C\u3001\u30ED\u30FC\u30AB\
    \u30EB\u30B8\u30E3\u30C3\u30B8\u304C\u5BFE\u5FDC\u3057\u3066\u3044\u306A\u3044\
    \u306E\u3067NG\r\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B\"\
    \r\n\r\n#include \"./snippet/at/header/header.hpp\"\r\n#include \"./snippet/at/graph/graph.hpp\"\
    \r\n#include \"./snippet/at/graph/Tsort.hpp\"\r\n\r\nint main(){\r\n    I(ll,\
    \ V, E);\r\n    graph g(V);\r\n    REP(i, E){\r\n        I(ll, s, t);\r\n    \
    \    g.add_diedge(s, t);\r\n    }\r\n\r\n    auto vs = Tsort(g);\r\n    REP(i,\
    \ V){\r\n        cout << vs[i] << el;\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - snippet/at/header/header.hpp
  - snippet/at/graph/graph.hpp
  - snippet/at/graph/Tsort.hpp
  isVerificationFile: true
  path: test/graph/Tsort.test.cpp
  requiredBy: []
  timestamp: '2021-06-18 19:49:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/Tsort.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Tsort.test.cpp
- /verify/test/graph/Tsort.test.cpp.html
title: test/graph/Tsort.test.cpp
---
