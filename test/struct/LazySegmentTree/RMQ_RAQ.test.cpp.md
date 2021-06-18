---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snippet/at/header/header.hpp
    title: snippet/at/header/header.hpp
  - icon: ':heavy_check_mark:'
    path: snippet/at/struct/LazySegmentTree.hpp
    title: snippet/at/struct/LazySegmentTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
  bundledCode: "#line 1 \"test/struct/LazySegmentTree/RMQ_RAQ.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\
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
    #pragma endregion\r\n#line 1 \"snippet/at/struct/LazySegmentTree.hpp\"\n// \u9045\
    \u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\r\n#pragma region LazySegmentTree\r\
    \n// https://ei1333.github.io/algorithm/segment-tree.html\r\n// [l, r)\r\nnamespace\
    \ LSTOpt{\r\n    using Monoid = ll;\r\n    using OpMonoid = ll;\r\n    // Command\u57FA\
    \u5E95\u30AF\u30E9\u30B9\u306E\u5BA3\u8A00\r\n    struct CmdM{\r\n        virtual\
    \ Monoid M() = 0;\r\n        virtual Monoid op(Monoid a, Monoid b) = 0;\r\n  \
    \      virtual OpMonoid p(OpMonoid a, size_t n) = 0;\r\n    };\r\n    struct CmdOp{\r\
    \n        virtual OpMonoid ID() = 0;\r\n        virtual Monoid mapping(Monoid\
    \ a, OpMonoid b) = 0;\r\n        virtual OpMonoid composition(OpMonoid a, OpMonoid\
    \ b) = 0;\r\n    };\r\n}\r\ntemplate< typename Monoid = LSTOpt::Monoid, typename\
    \ OperatorMonoid = LSTOpt::OpMonoid >\r\nstruct LST {\r\n    int sz;\r\n    vector<\
    \ Monoid > data;\r\n    vector< OperatorMonoid > lazy;\r\n    LSTOpt::CmdM* m;\r\
    \n    LSTOpt::CmdOp* op;\r\n    LST(int n, LSTOpt::CmdM* cmdm, LSTOpt::CmdOp*\
    \ cmdop)\r\n        //: f(cmdm.op), g(cmdop.mapping), h(cmdop.composition), p(cmdm.p),\
    \ M1(cmdm.M()), OM0(cmdop.ID())\r\n        {\r\n            this->m = cmdm;\r\n\
    \            this->op = cmdop;\r\n            sz = 1;\r\n            while(sz\
    \ < n) sz <<= 1;\r\n            data.assign(2 * sz, m->M());\r\n            lazy.assign(2\
    \ * sz, op->ID());\r\n        }\r\n\r\n    void set(int k, const Monoid &x) {\r\
    \n        data[k + sz] = x;\r\n    }\r\n    void build(){\r\n        for(int k\
    \ = sz - 1; k > 0; k--) {\r\n            data[k] = m->op(data[2 * k + 0], data[2\
    \ * k + 1]);\r\n        }\r\n    }\r\n    void propagate(int k, int len) {\r\n\
    \        if(lazy[k] != op->ID()) {\r\n            if(k < sz) {\r\n           \
    \     lazy[2 * k + 0] = op->composition(lazy[2 * k + 0], lazy[k]);\r\n       \
    \         lazy[2 * k + 1] = op->composition(lazy[2 * k + 1], lazy[k]);\r\n   \
    \         }\r\n            data[k] = op->mapping(data[k], m->p(lazy[k], len));\r\
    \n            lazy[k] = op->ID();\r\n        }\r\n    }\r\n    Monoid update(int\
    \ a, int b, const OperatorMonoid &x, int k, int l, int r) {\r\n        propagate(k,\
    \ r - l);\r\n        if(r <= a || b <= l) {\r\n            return data[k];\r\n\
    \        }else if(a <= l && r <= b) {\r\n            lazy[k] = op->composition(lazy[k],\
    \ x);\r\n            propagate(k, r - l);\r\n            return data[k];\r\n \
    \       }else{\r\n            return data[k] = m->op(update(a, b, x, 2 * k + 0,\
    \ l, (l + r) >> 1),\r\n                                update(a, b, x, 2 * k +\
    \ 1, (l + r) >> 1, r));\r\n        }\r\n    }\r\n    Monoid update(int a, int\
    \ b, const OperatorMonoid &x) {\r\n        return update(a, b, x, 1, 0, sz);\r\
    \n    }\r\n    Monoid query(int a, int b, int k, int l, int r){\r\n        propagate(k,\
    \ r - l);\r\n        if(r <= a || b <= l) {\r\n            return m->M();\r\n\
    \        }else if(a <= l && r <= b) {\r\n            return data[k];\r\n     \
    \   }else{\r\n            return m->op(query(a, b, 2 * k + 0, l, (l + r) >> 1),\r\
    \n                    query(a, b, 2 * k + 1, (l + r) >> 1, r));\r\n        }\r\
    \n    }\r\n    Monoid query(int a, int b) {\r\n        return query(a, b, 1, 0,\
    \ sz);\r\n    }\r\n    Monoid operator[](const int &k) {\r\n        return query(k,\
    \ k + 1);\r\n    }\r\n};\r\nnamespace LSTOpt{\r\n    struct secadd : CmdOp{\r\n\
    \        // \u5358\u4F4D\u5143\r\n        Monoid ID(){ return 0; }\r\n       \
    \ // \u8981\u7D20\u3068\u4F5C\u7528\u7D20\u306E\u30DE\u30FC\u30B8\r\n        Monoid\
    \ mapping(Monoid a, OpMonoid b) { return a + b; };\r\n        // \u4F5C\u7528\u7D20\
    \u3068\u4F5C\u7528\u7D20\u306E\u30DE\u30FC\u30B8\r\n        OpMonoid composition(OpMonoid\
    \ a, OpMonoid b) { return a + b; };\r\n    } ;\r\n    struct seccng : CmdOp{\r\
    \n        // \u5358\u4F4D\u5143 \u203B\u8981\u5909\u66F4\r\n        Monoid ID(){\
    \ return INF; }\r\n        // \u8981\u7D20\u3068\u4F5C\u7528\u7D20\u306E\u30DE\
    \u30FC\u30B8\r\n        Monoid mapping(Monoid a, OpMonoid b) { return (b==ID())?a:b;\
    \ };\r\n        // \u4F5C\u7528\u7D20\u3068\u4F5C\u7528\u7D20\u306E\u30DE\u30FC\
    \u30B8\r\n        OpMonoid composition(OpMonoid a, OpMonoid b) { return (b==ID())?a:b;\
    \ };\r\n    };\r\n    // min\r\n    struct secmin : CmdM{\r\n        // \u5358\
    \u4F4D\u5143\r\n        Monoid M(){ return INF; }\r\n        // \u6F14\u7B97\r\
    \n        Monoid op(Monoid a, Monoid b){ return std::min(a, b); }\r\n        //\
    \ \u4F5C\u7528\u7D20\u30DE\u30FC\u30B8\u306E\u524D\u306B\u304B\u307E\u305B\u308B\
    \u95A2\u6570\r\n        OpMonoid p(OpMonoid a, size_t n){ return a; }\r\n    };\r\
    \n    // sum\r\n    struct secsum : CmdM{\r\n        // \u5358\u4F4D\u5143\r\n\
    \        Monoid M(){ return 0; }\r\n        // \u6F14\u7B97\r\n        Monoid\
    \ op(Monoid a, Monoid b){ return a+b; }\r\n        // \u4F5C\u7528\u7D20\u30DE\
    \u30FC\u30B8\u306E\u524D\u306B\u304B\u307E\u305B\u308B\u95A2\u6570\r\n       \
    \ OpMonoid p(OpMonoid a, size_t n){ return a*n; }\r\n    };\r\n};\r\n#pragma endregion\n\
    #line 5 \"test/struct/LazySegmentTree/RMQ_RAQ.test.cpp\"\n\r\nint main(){\r\n\
    \    I(ll, N, Q);\r\n    LST lst(N, new LSTOpt::secmin(), new LSTOpt::secadd());\r\
    \n    REP(i, N){\r\n        lst.set(i, 0);\r\n    }\r\n    lst.build();\r\n  \
    \  REP(i, Q){\r\n        I(ll, q);\r\n        if(!q){\r\n            I(ll, s,\
    \ t, x);\r\n            lst.update(s, t+1, x);\r\n        }else{\r\n         \
    \   I(ll, s, t);\r\n            cout << lst.query(s, t+1) << el;\r\n        }\r\
    \n    }\r\n    return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\
    \r\n\r\n#include \"./snippet/at/header/header.hpp\"\r\n#include \"./snippet/at/struct/LazySegmentTree.hpp\"\
    \r\n\r\nint main(){\r\n    I(ll, N, Q);\r\n    LST lst(N, new LSTOpt::secmin(),\
    \ new LSTOpt::secadd());\r\n    REP(i, N){\r\n        lst.set(i, 0);\r\n    }\r\
    \n    lst.build();\r\n    REP(i, Q){\r\n        I(ll, q);\r\n        if(!q){\r\
    \n            I(ll, s, t, x);\r\n            lst.update(s, t+1, x);\r\n      \
    \  }else{\r\n            I(ll, s, t);\r\n            cout << lst.query(s, t+1)\
    \ << el;\r\n        }\r\n    }\r\n    return 0;\r\n}\r\n"
  dependsOn:
  - snippet/at/header/header.hpp
  - snippet/at/struct/LazySegmentTree.hpp
  isVerificationFile: true
  path: test/struct/LazySegmentTree/RMQ_RAQ.test.cpp
  requiredBy: []
  timestamp: '2021-06-18 20:18:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/struct/LazySegmentTree/RMQ_RAQ.test.cpp
layout: document
redirect_from:
- /verify/test/struct/LazySegmentTree/RMQ_RAQ.test.cpp
- /verify/test/struct/LazySegmentTree/RMQ_RAQ.test.cpp.html
title: test/struct/LazySegmentTree/RMQ_RAQ.test.cpp
---
