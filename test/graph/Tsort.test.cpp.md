---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: snippet/at/graph/tSort.hpp:\
    \ line -1: no such header\n"
  code: "// \u7B54\u3048\u304C\u8907\u6570\u3042\u308B\u304C\u3001\u30ED\u30FC\u30AB\
    \u30EB\u30B8\u30E3\u30C3\u30B8\u304C\u5BFE\u5FDC\u3057\u3066\u3044\u306A\u3044\
    \u306E\u3067NG\r\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B\"\
    \r\n\r\n#include \"./snippet/at/header/header.hpp\"\r\n#include \"./snippet/at/graph/graph.hpp\"\
    \r\n#include \"./snippet/at/graph/tSort.hpp\"\r\n\r\nint main(){\r\n    I(ll,\
    \ V, E);\r\n    graph g(V);\r\n    REP(i, E){\r\n        I(ll, s, t);\r\n    \
    \    g.add_diedge(s, t);\r\n    }\r\n\r\n    auto vs = tSort(g);\r\n    REP(i,\
    \ V){\r\n        cout << vs[i] << el;\r\n    }\r\n    return 0;\r\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/Tsort.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/Tsort.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Tsort.test.cpp
- /verify/test/graph/Tsort.test.cpp.html
title: test/graph/Tsort.test.cpp
---
