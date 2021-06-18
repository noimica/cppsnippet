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
  bundledCode: "#line 1 \"snippet/at/graph/mfgraph.hpp\"\n#pragma region mfgraph\r\
    \nstruct mfedge{\r\n    ll from, to, cost, rev;\r\n    bool operator<(const mfedge&\
    \ r) const{return cost<r.cost;}\r\n    bool operator>(const mfedge& r) const{return\
    \ cost>r.cost;}\r\n};\r\nstruct mfgraph{\r\n    vl level;\r\n    vl iter;\r\n\
    \    ll V;\r\n    vector<vector<mfedge> > G;\r\n    mfgraph(ll n){\r\n       \
    \ init(n);\r\n    }\r\n    void init(ll n){\r\n        V = n;\r\n        G.resize(V);\r\
    \n        iter.resize(V);\r\n        level.resize(V);\r\n    }\r\n    // \u7121\
    \u5411\u30B0\u30E9\u30D5\r\n    void add_edge(ll s, ll t, ll cost = 1){\r\n  \
    \      add_diedge(s, t, cost);\r\n        add_diedge(t, s, cost);\r\n    }\r\n\
    \    // \u6709\u5411\u30B0\u30E9\u30D5\r\n    void add_diedge(ll s, ll t, ll cost\
    \ = 1){\r\n        if(s < 0 || t < 0 || s >= V || t >= V) return;\r\n        mfedge\
    \ e1({s, t, cost, (ll)G[t].size()});\r\n        mfedge e2({t, s, 0, (ll)G[s].size()});\r\
    \n        G[s].push_back(e1);\r\n        G[t].push_back(e2);\r\n    }\r\n    //calculate\
    \ min Distance from start with BFS\r\n    void bfs(int s){\r\n        fill(ALL(level),\
    \ -1);\r\n        queue<int> que;\r\n        level[s]=0;\r\n        que.push(s);\r\
    \n        while (!que.empty()){\r\n            int v = que.front(); que.pop();\r\
    \n            REP(i, G[v].size()){\r\n                mfedge &e = G[v][i];\r\n\
    \                if (e.cost > 0 && level[e.to] < 0){\r\n                    level[e.to]\
    \ = level[v] + 1;\r\n                    que.push(e.to);\r\n                }\r\
    \n            }\r\n        }\r\n    }\r\n    //find path with DFS\r\n    int dfs(ll\
    \ v, ll t, ll f){\r\n        if (v==t) return f;\r\n\r\n        for (ll &i = iter[v];\
    \ i < G[v].size() ; i++){\r\n            mfedge &e = G[v][i];\r\n\r\n        \
    \    if (e.cost > 0 && level[v] < level[e.to]){\r\n                //do not search\
    \ for the edge which goes back\r\n                \r\n                int d =\
    \ dfs(e.to, t, min(f, e.cost));\r\n                if(d > 0){\r\n            \
    \        e.cost -= d;\r\n                    G[e.to][e.rev].cost += d;\r\n   \
    \                 return d;\r\n                }\r\n            }\r\n        }\r\
    \n        return 0;\r\n    }\r\n    ll max_flow(int s, int t){\r\n        ll flow\
    \ = 0;\r\n        while(1){\r\n            bfs(s);\r\n            if(level[t]\
    \ < 0) return flow;\r\n            fill(ALL(iter), 0);\r\n            ll f;\r\n\
    \            while ((f = dfs(s, t, INF)) > 0 ){\r\n                flow += f;\r\
    \n            }\r\n        }\r\n    }\r\n    auto pos2d(ll height, ll width){\r\
    \n        return [height, width](ll y, ll x){\r\n            return \r\n     \
    \           (y < 0 || y >= height || x < 0 || x >= width)\r\n                ?\
    \ -1\r\n                : y*width + x;\r\n        };\r\n    }\r\n};\r\n#pragma\
    \ endregion\n"
  code: "#pragma region mfgraph\r\nstruct mfedge{\r\n    ll from, to, cost, rev;\r\
    \n    bool operator<(const mfedge& r) const{return cost<r.cost;}\r\n    bool operator>(const\
    \ mfedge& r) const{return cost>r.cost;}\r\n};\r\nstruct mfgraph{\r\n    vl level;\r\
    \n    vl iter;\r\n    ll V;\r\n    vector<vector<mfedge> > G;\r\n    mfgraph(ll\
    \ n){\r\n        init(n);\r\n    }\r\n    void init(ll n){\r\n        V = n;\r\
    \n        G.resize(V);\r\n        iter.resize(V);\r\n        level.resize(V);\r\
    \n    }\r\n    // \u7121\u5411\u30B0\u30E9\u30D5\r\n    void add_edge(ll s, ll\
    \ t, ll cost = 1){\r\n        add_diedge(s, t, cost);\r\n        add_diedge(t,\
    \ s, cost);\r\n    }\r\n    // \u6709\u5411\u30B0\u30E9\u30D5\r\n    void add_diedge(ll\
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
    \ }\r\n};\r\n#pragma endregion"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/mfgraph.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/graph/mfgraph.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/mfgraph.hpp
- /library/snippet/at/graph/mfgraph.hpp.html
title: snippet/at/graph/mfgraph.hpp
---
