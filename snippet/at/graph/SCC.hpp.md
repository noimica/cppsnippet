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
  bundledCode: "#line 1 \"snippet/at/graph/SCC.hpp\"\n// \u5F37\u9023\u7D50\u6210\u5206\
    \u5206\u89E3\r\n// O(V+E);\r\nstruct SCC {\r\n    const int V;\r\n    graph g,\
    \ rg;\r\n    vector<bool> visit;\r\n    vector<int> comp, order;\r\n    vector<vector<int>>\
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
    \n            }\r\n            ++cnt;\r\n        }\r\n    }\r\n};\n"
  code: "// \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\r\n// O(V+E);\r\nstruct SCC\
    \ {\r\n    const int V;\r\n    graph g, rg;\r\n    vector<bool> visit;\r\n   \
    \ vector<int> comp, order;\r\n    vector<vector<int>> components;\r\n\r\n    SCC(const\
    \ graph &g) : V(g.V), g(g), rg(V), visit(V, false), comp(V, -1) {\r\n        //\
    \ \u8FBA\u306E\u5411\u304D\u3092\u9006\u306B\u3057\u305F\u30B0\u30E9\u30D5\u3092\
    \u69CB\u7BC9\r\n        for (int v = 0; v < V; ++v) {\r\n            for (auto\
    \ &e : g.G[v]) {\r\n                rg.add_diedge(e.to, e.from, e.cost);\r\n \
    \           }\r\n        }\r\n        build();\r\n    }\r\n\r\n    // \u540C\u3058\
    \u5F37\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3057\u3066\u3044\u308C\u3070true\u3092\
    \u8FD4\u3059\r\n    bool same(int s, int t) { \r\n        assert(comp[s] != -1\
    \ && comp[t] != -1);\r\n        return comp[s] == comp[t];\r\n    }\r\n\r\n  \
    \  void dfs(int sv) { \r\n        if (visit[sv]) return;\r\n        visit[sv]\
    \ = true;\r\n        for (auto &e : g.G[sv]) { \r\n            dfs(e.to);\r\n\
    \        }\r\n        order.push_back(sv);\r\n    }\r\n\r\n    void rdfs(int sv,\
    \ int cnt) { \r\n        if (comp[sv] != -1) return;\r\n        comp[sv] = cnt;\r\
    \n\r\n        if (components.size() <= cnt) { \r\n            vector<int> v;\r\
    \n            components.push_back(v);\r\n        }\r\n        components[cnt].push_back(sv);\r\
    \n\r\n        for (auto &e : rg.G[sv]) { \r\n            rdfs(e.to, cnt);\r\n\
    \        }\r\n    }\r\n\r\n    void build() {\r\n        for(int i = 0; i < V;\
    \ i++) { dfs(i); } \r\n        assert(order.size() == V);\r\n        reverse(order.begin(),\
    \ order.end()); // dfs\u3067\u3064\u3051\u305F\u756A\u53F7\u3092\u9006\u9806\u306B\
    \u3059\u308B\r\n        int cnt = 0; // \u5F37\u9023\u7D50\u6210\u5206\u6BCE\u306E\
    id\r\n        for (int v : order) { \r\n            if (comp[v] != -1) continue;\r\
    \n            rdfs(v, cnt);\r\n            // \u5F37\u9023\u7D50\u6210\u5206\u306E\
    \u9802\u70B9\u3092\u30EB\u30FC\u30D7\u306E\u9806\u306B\u4E26\u3073\u66FF\u3048\
    \r\n            if (components[cnt].size() > 1) {\r\n                reverse(components[cnt].begin()+1,\
    \ components[cnt].end());\r\n            }\r\n            ++cnt;\r\n        }\r\
    \n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/SCC.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/graph/SCC.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/SCC.hpp
- /library/snippet/at/graph/SCC.hpp.html
title: snippet/at/graph/SCC.hpp
---
