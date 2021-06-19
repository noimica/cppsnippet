---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snippet/at/graph/LCA.hpp
    title: snippet/at/graph/LCA.hpp
  - icon: ':heavy_check_mark:'
    path: snippet/at/graph/graph.hpp
    title: snippet/at/graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: snippet/at/header/header.hpp
    title: snippet/at/header/header.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
  bundledCode: "#line 1 \"test/graph/LCA.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
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
    #pragma endregion\r\n#line 1 \"snippet/at/graph/graph.hpp\"\n#pragma region graph\r\
    \nstruct edge{\r\n    ll from, to, cost;\r\n    bool operator<(const edge& r)\
    \ const{return cost<r.cost;}\r\n    bool operator>(const edge& r) const{return\
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
    \ 1 \"snippet/at/graph/LCA.hpp\"\n// \u6700\u5C0F\u5171\u901A\u7956\u5148\r\n\r\
    \n// \u524D\u51E6\u7406 O(NlogN), \u30AF\u30A8\u30EA O(logN)\r\n\r\nstruct LCA\
    \ {\r\n    vector<vector<int>> parent;  // parent[k][u]:= u \u306E 2^k \u5148\u306E\
    \u89AA\r\n\r\n    vector<int> dist;            // root \u304B\u3089\u306E\u8DDD\
    \u96E2\r\n\r\n    LCA(const graph &g, int root = 0) { init(g, root); }\r\n   \
    \ // \u521D\u671F\u5316\r\n\r\n    void init(const graph &g, int root = 0) {\r\
    \n        ll V = g.V;\r\n        ll K = __builtin_popcountll(LONG_LONG_MAX) -\
    \ __builtin_clzll(V) + 1;\r\n        parent.assign(K, vector<int>(V, -1));\r\n\
    \        dist.assign(V, -1);\r\n        dfs(g, root, -1, 0);\r\n        for (int\
    \ k = 0; k + 1 < K; k++) {\r\n            for (int v = 0; v < V; v++) {\r\n  \
    \              if (parent[k][v] < 0) {\r\n                    parent[k + 1][v]\
    \ = -1;\r\n                } else {\r\n                    parent[k + 1][v] =\
    \ parent[k][parent[k][v]];\r\n                }\r\n            }\r\n        }\r\
    \n    }\r\n    // \u6839\u304B\u3089\u306E\u8DDD\u96E2\u30681\u3064\u5148\u306E\
    \u9802\u70B9\u3092\u6C42\u3081\u308B\r\n\r\n    void dfs(const graph &g, int v,\
    \ int p, int d) {\r\n        parent[0][v] = p;\r\n        dist[v] = d;\r\n   \
    \     for (auto e : g.G[v]) {\r\n            if (e.to != p) dfs(g, e.to, v, d\
    \ + 1);\r\n        }\r\n    }\r\n    int query(int u, int v) {\r\n        if (dist[u]\
    \ < dist[v]) swap(u, v);  // u \u306E\u65B9\u304C\u6DF1\u3044\u3068\u3059\u308B\
    \r\n\r\n        int K = parent.size();\r\n        // LCA \u307E\u3067\u306E\u8DDD\
    \u96E2\u3092\u540C\u3058\u306B\u3059\u308B\r\n\r\n        for (int k = 0; k <\
    \ K; k++) {\r\n            if ((dist[u] - dist[v]) >> k & 1) {\r\n           \
    \     u = parent[k][u];\r\n            }\r\n        }\r\n        // \u4E8C\u5206\
    \u63A2\u7D22\u3067 LCA \u3092\u6C42\u3081\u308B\r\n\r\n        if (u == v) return\
    \ u;\r\n        for (int k = K - 1; k >= 0; k--) {\r\n            if (parent[k][u]\
    \ != parent[k][v]) {\r\n                u = parent[k][u];\r\n                v\
    \ = parent[k][v];\r\n            }\r\n        }\r\n        return parent[0][u];\r\
    \n    }\r\n};\n#line 6 \"test/graph/LCA.test.cpp\"\n\r\nint main(){\r\n    I(ll,\
    \ N);\r\n    graph g(N);\r\n    REP(i, N){\r\n        I(ll, k);\r\n        REP(j,\
    \ k){\r\n            I(ll, c);\r\n            g.add_edge(i, c);\r\n        }\r\
    \n    }\r\n    LCA lca(g);\r\n    I(ll, Q);\r\n    REP(i, Q){\r\n        I(ll,\
    \ u, v);\r\n        cout << lca.query(u, v) << el;\r\n    }\r\n    return 0;\r\
    \n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \r\n\r\n#include \"./snippet/at/header/header.hpp\"\r\n#include \"./snippet/at/graph/graph.hpp\"\
    \r\n#include \"./snippet/at/graph/LCA.hpp\"\r\n\r\nint main(){\r\n    I(ll, N);\r\
    \n    graph g(N);\r\n    REP(i, N){\r\n        I(ll, k);\r\n        REP(j, k){\r\
    \n            I(ll, c);\r\n            g.add_edge(i, c);\r\n        }\r\n    }\r\
    \n    LCA lca(g);\r\n    I(ll, Q);\r\n    REP(i, Q){\r\n        I(ll, u, v);\r\
    \n        cout << lca.query(u, v) << el;\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - snippet/at/header/header.hpp
  - snippet/at/graph/graph.hpp
  - snippet/at/graph/LCA.hpp
  isVerificationFile: true
  path: test/graph/LCA.test.cpp
  requiredBy: []
  timestamp: '2021-06-19 23:22:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/LCA.test.cpp
layout: document
redirect_from:
- /verify/test/graph/LCA.test.cpp
- /verify/test/graph/LCA.test.cpp.html
title: test/graph/LCA.test.cpp
---
