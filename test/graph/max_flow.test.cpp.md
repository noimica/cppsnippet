---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snippet/at/graph/mfgraph.hpp
    title: snippet/at/graph/mfgraph.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"test/graph/max_flow.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
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
    #pragma endregion\r\n#line 1 \"snippet/at/graph/mfgraph.hpp\"\n#pragma region\
    \ mfgraph\r\nstruct mfedge{\r\n    ll from, to, cost, rev;\r\n    bool operator<(const\
    \ mfedge& r) const{return cost<r.cost;}\r\n    bool operator>(const mfedge& r)\
    \ const{return cost>r.cost;}\r\n};\r\nstruct mfgraph{\r\n    vl level;\r\n   \
    \ vl iter;\r\n    ll V;\r\n    vector<vector<mfedge> > G;\r\n    mfgraph(ll n){\r\
    \n        init(n);\r\n    }\r\n    void init(ll n){\r\n        V = n;\r\n    \
    \    G.resize(V);\r\n        iter.resize(V);\r\n        level.resize(V);\r\n \
    \   }\r\n    // \u7121\u5411\u30B0\u30E9\u30D5\r\n    void add_edge(ll s, ll t,\
    \ ll cost = 1){\r\n        add_diedge(s, t, cost);\r\n        add_diedge(t, s,\
    \ cost);\r\n    }\r\n    // \u6709\u5411\u30B0\u30E9\u30D5\r\n    void add_diedge(ll\
    \ s, ll t, ll cost = 1){\r\n        if(s < 0 || t < 0 || s >= V || t >= V) return;\r\
    \n        mfedge e1({s, t, cost, (ll)G[t].size()});\r\n        mfedge e2({t, s,\
    \ 0, (ll)G[s].size()});\r\n        G[s].push_back(e1);\r\n        G[t].push_back(e2);\r\
    \n    }\r\n    //calculate min Distance from start with BFS\r\n    void bfs(int\
    \ s){\r\n        fill(ALL(level), -1);\r\n        queue<int> que;\r\n        level[s]=0;\r\
    \n        que.push(s);\r\n        while (!que.empty()){\r\n            int v =\
    \ que.front(); que.pop();\r\n            REP(i, G[v].size()){\r\n            \
    \    mfedge &e = G[v][i];\r\n                if (e.cost > 0 && level[e.to] < 0){\r\
    \n                    level[e.to] = level[v] + 1;\r\n                    que.push(e.to);\r\
    \n                }\r\n            }\r\n        }\r\n    }\r\n    //find path\
    \ with DFS\r\n    int dfs(ll v, ll t, ll f){\r\n        if (v==t) return f;\r\n\
    \r\n        for (ll &i = iter[v]; i < G[v].size() ; i++){\r\n            mfedge\
    \ &e = G[v][i];\r\n\r\n            if (e.cost > 0 && level[v] < level[e.to]){\r\
    \n                //do not search for the edge which goes back\r\n           \
    \     \r\n                int d = dfs(e.to, t, min(f, e.cost));\r\n          \
    \      if(d > 0){\r\n                    e.cost -= d;\r\n                    G[e.to][e.rev].cost\
    \ += d;\r\n                    return d;\r\n                }\r\n            }\r\
    \n        }\r\n        return 0;\r\n    }\r\n    ll max_flow(int s, int t){\r\n\
    \        ll flow = 0;\r\n        while(1){\r\n            bfs(s);\r\n        \
    \    if(level[t] < 0) return flow;\r\n            fill(ALL(iter), 0);\r\n    \
    \        ll f;\r\n            while ((f = dfs(s, t, INF)) > 0 ){\r\n         \
    \       flow += f;\r\n            }\r\n        }\r\n    }\r\n    auto pos2d(ll\
    \ height, ll width){\r\n        return [height, width](ll y, ll x){\r\n      \
    \      return \r\n                (y < 0 || y >= height || x < 0 || x >= width)\r\
    \n                ? -1\r\n                : y*width + x;\r\n        };\r\n   \
    \ }\r\n};\r\n#pragma endregion\n#line 5 \"test/graph/max_flow.test.cpp\"\n\r\n\
    int main(){\r\n    I(ll, V, E);\r\n    mfgraph g(V);\r\n    REP(i, E){\r\n   \
    \     I(ll, s, t, d);\r\n        g.add_diedge(s, t, d);\r\n    }\r\n    ll w =\
    \ g.max_flow(0, V-1);\r\n    cout << w << el;\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \r\n\r\n#include \"./snippet/at/header/header.hpp\"\r\n#include \"./snippet/at/graph/mfgraph.hpp\"\
    \r\n\r\nint main(){\r\n    I(ll, V, E);\r\n    mfgraph g(V);\r\n    REP(i, E){\r\
    \n        I(ll, s, t, d);\r\n        g.add_diedge(s, t, d);\r\n    }\r\n    ll\
    \ w = g.max_flow(0, V-1);\r\n    cout << w << el;\r\n    return 0;\r\n}"
  dependsOn:
  - snippet/at/header/header.hpp
  - snippet/at/graph/mfgraph.hpp
  isVerificationFile: true
  path: test/graph/max_flow.test.cpp
  requiredBy: []
  timestamp: '2021-06-19 19:07:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/max_flow.test.cpp
layout: document
redirect_from:
- /verify/test/graph/max_flow.test.cpp
- /verify/test/graph/max_flow.test.cpp.html
title: test/graph/max_flow.test.cpp
---
