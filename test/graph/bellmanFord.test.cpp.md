---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snippet/at/graph/bellmanFord.hpp
    title: snippet/at/graph/bellmanFord.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"test/graph/bellmanFord.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
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
    \ 1 \"snippet/at/graph/bellmanFord.hpp\"\n#pragma region bellmanFord\r\n// O(|E||V|)\r\
    \npair<bool, umap<ll, ll>> bellmanFord(int V, const vector<edge> &edges, int s){\r\
    \n    vector<ll> dist(V, INF);\r\n    umap<ll, ll> ret;\r\n    ret[s] = dist[s]\
    \ = 0;\r\n    bool is_negative_cycle = true;\r\n    REP(cnt, V){\r\n        bool\
    \ end = true;\r\n        for (auto e : edges) {\r\n            if (dist[e.from]\
    \ != INF && dist[e.from] + e.cost < dist[e.to]) {\r\n                ret[e.to]\
    \ = dist[e.to] = dist[e.from] + e.cost;\r\n                end = false;\r\n  \
    \          }\r\n        }\r\n        if (end){\r\n            // \u3053\u3053\u3067\
    \u629C\u3051\u306A\u304B\u3063\u305F\u3089\u8CA0\u306E\u9589\u8DEF\u304C\u3042\
    \u308B\r\n            is_negative_cycle = false;\r\n            break;\r\n   \
    \     }\r\n    }\r\n    return {is_negative_cycle, ret};\r\n}\r\npair<bool, umap<ll,\
    \ ll>> bellmanFord(const graph& g, int s) {\r\n    int V = g.V;\r\n    vector<edge>\
    \ edges;\r\n    REP(i, V){\r\n        for(auto e : g.G[i]){\r\n            edges.emplace_back(e);\r\
    \n        }\r\n    }\r\n    return bellmanFord(V, edges, s);\r\n}\r\n#pragma endregion\n\
    #line 6 \"test/graph/bellmanFord.test.cpp\"\n\r\nint main(){\r\n    I(ll, V, E,\
    \ r);\r\n    graph g(V);\r\n    REP(i, E){\r\n        I(ll, s, t, d);\r\n    \
    \    g.add_diedge(s, t, d);\r\n    }\r\n\r\n    auto [nc, d] = bellmanFord(g,\
    \ r);\r\n    if(nc){\r\n        cout << \"NEGATIVE CYCLE\" << el;\r\n        return\
    \ 0;\r\n    }\r\n    REP(i, V){\r\n        if(d.find(i) != d.end()){\r\n     \
    \       cout << d[i] << el;\r\n        }else{\r\n            cout << \"INF\" <<\
    \ el;\r\n        }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \r\n\r\n#include \"./snippet/at/header/header.hpp\"\r\n#include \"./snippet/at/graph/graph.hpp\"\
    \r\n#include \"./snippet/at/graph/bellmanFord.hpp\"\r\n\r\nint main(){\r\n   \
    \ I(ll, V, E, r);\r\n    graph g(V);\r\n    REP(i, E){\r\n        I(ll, s, t,\
    \ d);\r\n        g.add_diedge(s, t, d);\r\n    }\r\n\r\n    auto [nc, d] = bellmanFord(g,\
    \ r);\r\n    if(nc){\r\n        cout << \"NEGATIVE CYCLE\" << el;\r\n        return\
    \ 0;\r\n    }\r\n    REP(i, V){\r\n        if(d.find(i) != d.end()){\r\n     \
    \       cout << d[i] << el;\r\n        }else{\r\n            cout << \"INF\" <<\
    \ el;\r\n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - snippet/at/header/header.hpp
  - snippet/at/graph/graph.hpp
  - snippet/at/graph/bellmanFord.hpp
  isVerificationFile: true
  path: test/graph/bellmanFord.test.cpp
  requiredBy: []
  timestamp: '2021-06-19 19:07:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/bellmanFord.test.cpp
layout: document
redirect_from:
- /verify/test/graph/bellmanFord.test.cpp
- /verify/test/graph/bellmanFord.test.cpp.html
title: test/graph/bellmanFord.test.cpp
---
