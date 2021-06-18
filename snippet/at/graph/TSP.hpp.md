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
  bundledCode: "#line 1 \"snippet/at/graph/TSP.hpp\"\n// \u5DE1\u56DE\u30BB\u30FC\u30EB\
    \u30B9\u30DE\u30F3\u554F\u984C(N^2 2^N)\r\nstruct TSP{\r\n    int V;\r\n    vector<vector<ll>>\
    \ dist, dp;\r\n    TSP(graph& _g): V(_g.V), dist(_g.V, vector<ll>(_g.V, INF)),\
    \ dp(1<<_g.V, vector<ll>(_g.V, -1)){\r\n        REP(i, V){\r\n            EACH(e,\
    \ _g.G[i]){\r\n                dist[e.from][e.to] = e.cost;\r\n            }\r\
    \n        }\r\n    }\r\n    ll calc(){return calc(0);}\r\n    ll calc(int v){\r\
    \n        // \u623B\u3089\u306A\u3044\u5834\u5408\u3001s\u3092((1ll<<V)-1ll)&~(1ll<<v)\u306B\
    \r\n        return calc(v, 0);\r\n    }\r\n    ll calc(int v, int s){\r\n    \
    \    // dp[bit][\u958B\u59CB\u9802\u70B9\u2208bit]\r\n        if(dp[s][v] >= 0){\r\
    \n            return dp[s][v];\r\n        }\r\n\r\n        if(s == 0){\r\n   \
    \         return dp[s][v] = 0;\r\n        }\r\n\r\n        ll ans = INF;\r\n \
    \       REP(u, V){\r\n            if(s&(1ll<<u)){\r\n                ans = min(ans,\
    \ calc(u, s&~(1<<u)) + dist[v][u]);\r\n            }\r\n        }\r\n\r\n    \
    \    return dp[s][v] = ans;\r\n    }\r\n};\n"
  code: "// \u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C(N^2 2^N)\r\
    \nstruct TSP{\r\n    int V;\r\n    vector<vector<ll>> dist, dp;\r\n    TSP(graph&\
    \ _g): V(_g.V), dist(_g.V, vector<ll>(_g.V, INF)), dp(1<<_g.V, vector<ll>(_g.V,\
    \ -1)){\r\n        REP(i, V){\r\n            EACH(e, _g.G[i]){\r\n           \
    \     dist[e.from][e.to] = e.cost;\r\n            }\r\n        }\r\n    }\r\n\
    \    ll calc(){return calc(0);}\r\n    ll calc(int v){\r\n        // \u623B\u3089\
    \u306A\u3044\u5834\u5408\u3001s\u3092((1ll<<V)-1ll)&~(1ll<<v)\u306B\r\n      \
    \  return calc(v, 0);\r\n    }\r\n    ll calc(int v, int s){\r\n        // dp[bit][\u958B\
    \u59CB\u9802\u70B9\u2208bit]\r\n        if(dp[s][v] >= 0){\r\n            return\
    \ dp[s][v];\r\n        }\r\n\r\n        if(s == 0){\r\n            return dp[s][v]\
    \ = 0;\r\n        }\r\n\r\n        ll ans = INF;\r\n        REP(u, V){\r\n   \
    \         if(s&(1ll<<u)){\r\n                ans = min(ans, calc(u, s&~(1<<u))\
    \ + dist[v][u]);\r\n            }\r\n        }\r\n\r\n        return dp[s][v]\
    \ = ans;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/TSP.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/graph/TSP.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/TSP.hpp
- /library/snippet/at/graph/TSP.hpp.html
title: snippet/at/graph/TSP.hpp
---
