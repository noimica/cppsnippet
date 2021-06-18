---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/Tsort.test.cpp
    title: test/graph/Tsort.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"snippet/at/graph/Tsort.hpp\"\n// \u30C8\u30DD\u30ED\u30B8\
    \u30AB\u30EB\u30BD\u30FC\u30C8 O(V+E)\r\nvl Tsort(const graph &g) {  // bfs\r\n\
    \    vl ans;\r\n    int n = (int)g.V;\r\n    vl ind(n);            // ind[i]:\
    \ \u9802\u70B9i\u306B\u5165\u308B\u8FBA\u306E\u6570(\u6B21\u6570)\r\n    for (int\
    \ i = 0; i < n; i++) {  // \u6B21\u6570\u3092\u6570\u3048\u3066\u304A\u304F\r\n\
    \        for (auto e : g.G[i]) {\r\n            ind[e.to]++;\r\n        }\r\n\
    \    }\r\n    queue<int> que;\r\n    for (int i = 0; i < n; i++) {  // \u6B21\u6570\
    \u304C0\u306E\u70B9\u3092\u30AD\u30E5\u30FC\u306B\u5165\u308C\u308B\r\n      \
    \  if (ind[i] == 0) {\r\n            que.push(i);\r\n        }\r\n    }\r\n  \
    \  while (!que.empty()) {  // \u5E45\u512A\u5148\u63A2\u7D22\r\n        int now\
    \ = que.front();\r\n        ans.push_back(now);\r\n        que.pop();\r\n    \
    \    for (auto e : g.G[now]) {\r\n            ind[e.to]--;\r\n            if (ind[e.to]\
    \ == 0) {\r\n                que.push(e.to);\r\n            }\r\n        }\r\n\
    \    }\r\n    return ans;\r\n}\n"
  code: "// \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8 O(V+E)\r\nvl Tsort(const\
    \ graph &g) {  // bfs\r\n    vl ans;\r\n    int n = (int)g.V;\r\n    vl ind(n);\
    \            // ind[i]: \u9802\u70B9i\u306B\u5165\u308B\u8FBA\u306E\u6570(\u6B21\
    \u6570)\r\n    for (int i = 0; i < n; i++) {  // \u6B21\u6570\u3092\u6570\u3048\
    \u3066\u304A\u304F\r\n        for (auto e : g.G[i]) {\r\n            ind[e.to]++;\r\
    \n        }\r\n    }\r\n    queue<int> que;\r\n    for (int i = 0; i < n; i++)\
    \ {  // \u6B21\u6570\u304C0\u306E\u70B9\u3092\u30AD\u30E5\u30FC\u306B\u5165\u308C\
    \u308B\r\n        if (ind[i] == 0) {\r\n            que.push(i);\r\n        }\r\
    \n    }\r\n    while (!que.empty()) {  // \u5E45\u512A\u5148\u63A2\u7D22\r\n \
    \       int now = que.front();\r\n        ans.push_back(now);\r\n        que.pop();\r\
    \n        for (auto e : g.G[now]) {\r\n            ind[e.to]--;\r\n          \
    \  if (ind[e.to] == 0) {\r\n                que.push(e.to);\r\n            }\r\
    \n        }\r\n    }\r\n    return ans;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/graph/Tsort.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/Tsort.test.cpp
documentation_of: snippet/at/graph/Tsort.hpp
layout: document
redirect_from:
- /library/snippet/at/graph/Tsort.hpp
- /library/snippet/at/graph/Tsort.hpp.html
title: snippet/at/graph/Tsort.hpp
---