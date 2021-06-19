---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snippet/at/graph/SCC.hpp
    title: snippet/at/graph/SCC.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
  bundledCode: "#line 1 \"test/graph/SCC.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C\"\
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
    \ 1 \"snippet/at/graph/SCC.hpp\"\n// \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \r\n// O(V+E);\r\nstruct SCC {\r\n    const int V;\r\n    graph g, rg;\r\n   \
    \ vector<bool> visit;\r\n    vector<int> comp, order;\r\n    vector<vector<int>>\
    \ components;\r\n\r\n    SCC(const graph &g) : V(g.V), g(g), rg(V), visit(V, false),\
    \ comp(V, -1) {\r\n        // \u8FBA\u306E\u5411\u304D\u3092\u9006\u306B\u3057\
    \u305F\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\r\n        for (int v = 0; v < V; ++v)\
    \ {\r\n            for (auto &e : g.G[v]) {\r\n                rg.add_diedge(e.to,\
    \ e.from, e.cost);\r\n            }\r\n        }\r\n        build();\r\n    }\r\
    \n\r\n    // \u540C\u3058\u5F37\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3057\u3066\
    \u3044\u308C\u3070true\u3092\u8FD4\u3059\r\n    bool same(int s, int t) { \r\n\
    \        assert(comp[s] != -1 && comp[t] != -1);\r\n        return comp[s] ==\
    \ comp[t];\r\n    }\r\n\r\n    void dfs(int sv) { \r\n        if (visit[sv]) return;\r\
    \n        visit[sv] = true;\r\n        for (auto &e : g.G[sv]) { \r\n        \
    \    dfs(e.to);\r\n        }\r\n        order.push_back(sv);\r\n    }\r\n\r\n\
    \    void rdfs(int sv, int cnt) { \r\n        if (comp[sv] != -1) return;\r\n\
    \        comp[sv] = cnt;\r\n\r\n        if (components.size() <= cnt) { \r\n \
    \           vector<int> v;\r\n            components.push_back(v);\r\n       \
    \ }\r\n        components[cnt].push_back(sv);\r\n\r\n        for (auto &e : rg.G[sv])\
    \ { \r\n            rdfs(e.to, cnt);\r\n        }\r\n    }\r\n\r\n    void build()\
    \ {\r\n        for(int i = 0; i < V; i++) { dfs(i); } \r\n        assert(order.size()\
    \ == V);\r\n        reverse(order.begin(), order.end()); // dfs\u3067\u3064\u3051\
    \u305F\u756A\u53F7\u3092\u9006\u9806\u306B\u3059\u308B\r\n        int cnt = 0;\
    \ // \u5F37\u9023\u7D50\u6210\u5206\u6BCE\u306Eid\r\n        for (int v : order)\
    \ { \r\n            if (comp[v] != -1) continue;\r\n            rdfs(v, cnt);\r\
    \n            // \u5F37\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u3092\u30EB\u30FC\
    \u30D7\u306E\u9806\u306B\u4E26\u3073\u66FF\u3048\r\n            if (components[cnt].size()\
    \ > 1) {\r\n                reverse(components[cnt].begin()+1, components[cnt].end());\r\
    \n            }\r\n            ++cnt;\r\n        }\r\n    }\r\n};\n#line 6 \"\
    test/graph/SCC.test.cpp\"\n\r\nint main(){\r\n    I(ll, V, E);\r\n    graph g(V);\r\
    \n    REP(i, E){\r\n        I(ll, s, t);\r\n        g.add_diedge(s, t);\r\n  \
    \  }\r\n\r\n    SCC scc(g);\r\n    scc.build();\r\n\r\n    I(ll, Q);\r\n    REP(i,\
    \ Q){\r\n        I(ll, u, v);\r\n        auto w = scc.same(u, v);\r\n        cout\
    \ << w << el;\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C\"\
    \r\n\r\n#include \"./snippet/at/header/header.hpp\"\r\n#include \"./snippet/at/graph/graph.hpp\"\
    \r\n#include \"./snippet/at/graph/SCC.hpp\"\r\n\r\nint main(){\r\n    I(ll, V,\
    \ E);\r\n    graph g(V);\r\n    REP(i, E){\r\n        I(ll, s, t);\r\n       \
    \ g.add_diedge(s, t);\r\n    }\r\n\r\n    SCC scc(g);\r\n    scc.build();\r\n\r\
    \n    I(ll, Q);\r\n    REP(i, Q){\r\n        I(ll, u, v);\r\n        auto w =\
    \ scc.same(u, v);\r\n        cout << w << el;\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - snippet/at/header/header.hpp
  - snippet/at/graph/graph.hpp
  - snippet/at/graph/SCC.hpp
  isVerificationFile: true
  path: test/graph/SCC.test.cpp
  requiredBy: []
  timestamp: '2021-06-19 19:07:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/SCC.test.cpp
layout: document
redirect_from:
- /verify/test/graph/SCC.test.cpp
- /verify/test/graph/SCC.test.cpp.html
title: test/graph/SCC.test.cpp
---
