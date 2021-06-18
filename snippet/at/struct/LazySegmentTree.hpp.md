---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/struct/LazySegmentTree/RMQ_RAQ.test.cpp
    title: test/struct/LazySegmentTree/RMQ_RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/struct/LazySegmentTree/RMQ_RUQ.test.cpp
    title: test/struct/LazySegmentTree/RMQ_RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/struct/LazySegmentTree/RSQ_RAQ.test.cpp
    title: test/struct/LazySegmentTree/RSQ_RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/struct/LazySegmentTree/RSQ_RUQ.test.cpp
    title: test/struct/LazySegmentTree/RSQ_RUQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ei1333.github.io/algorithm/segment-tree.html
  bundledCode: "#line 1 \"snippet/at/struct/LazySegmentTree.hpp\"\n// \u9045\u5EF6\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\r\n#pragma region LazySegmentTree\r\n// https://ei1333.github.io/algorithm/segment-tree.html\r\
    \n// [l, r)\r\nnamespace LSTOpt{\r\n    using Monoid = ll;\r\n    using OpMonoid\
    \ = ll;\r\n    // Command\u57FA\u5E95\u30AF\u30E9\u30B9\u306E\u5BA3\u8A00\r\n\
    \    struct CmdM{\r\n        virtual Monoid M() = 0;\r\n        virtual Monoid\
    \ op(Monoid a, Monoid b) = 0;\r\n        virtual OpMonoid p(OpMonoid a, size_t\
    \ n) = 0;\r\n    };\r\n    struct CmdOp{\r\n        virtual OpMonoid ID() = 0;\r\
    \n        virtual Monoid mapping(Monoid a, OpMonoid b) = 0;\r\n        virtual\
    \ OpMonoid composition(OpMonoid a, OpMonoid b) = 0;\r\n    };\r\n}\r\ntemplate<\
    \ typename Monoid = LSTOpt::Monoid, typename OperatorMonoid = LSTOpt::OpMonoid\
    \ >\r\nstruct LST {\r\n    int sz;\r\n    vector< Monoid > data;\r\n    vector<\
    \ OperatorMonoid > lazy;\r\n    LSTOpt::CmdM* m;\r\n    LSTOpt::CmdOp* op;\r\n\
    \    LST(int n, LSTOpt::CmdM* cmdm, LSTOpt::CmdOp* cmdop)\r\n        //: f(cmdm.op),\
    \ g(cmdop.mapping), h(cmdop.composition), p(cmdm.p), M1(cmdm.M()), OM0(cmdop.ID())\r\
    \n        {\r\n            this->m = cmdm;\r\n            this->op = cmdop;\r\n\
    \            sz = 1;\r\n            while(sz < n) sz <<= 1;\r\n            data.assign(2\
    \ * sz, m->M());\r\n            lazy.assign(2 * sz, op->ID());\r\n        }\r\n\
    \r\n    void set(int k, const Monoid &x) {\r\n        data[k + sz] = x;\r\n  \
    \  }\r\n    void build(){\r\n        for(int k = sz - 1; k > 0; k--) {\r\n   \
    \         data[k] = m->op(data[2 * k + 0], data[2 * k + 1]);\r\n        }\r\n\
    \    }\r\n    void propagate(int k, int len) {\r\n        if(lazy[k] != op->ID())\
    \ {\r\n            if(k < sz) {\r\n                lazy[2 * k + 0] = op->composition(lazy[2\
    \ * k + 0], lazy[k]);\r\n                lazy[2 * k + 1] = op->composition(lazy[2\
    \ * k + 1], lazy[k]);\r\n            }\r\n            data[k] = op->mapping(data[k],\
    \ m->p(lazy[k], len));\r\n            lazy[k] = op->ID();\r\n        }\r\n   \
    \ }\r\n    Monoid update(int a, int b, const OperatorMonoid &x, int k, int l,\
    \ int r) {\r\n        propagate(k, r - l);\r\n        if(r <= a || b <= l) {\r\
    \n            return data[k];\r\n        }else if(a <= l && r <= b) {\r\n    \
    \        lazy[k] = op->composition(lazy[k], x);\r\n            propagate(k, r\
    \ - l);\r\n            return data[k];\r\n        }else{\r\n            return\
    \ data[k] = m->op(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),\r\n           \
    \                     update(a, b, x, 2 * k + 1, (l + r) >> 1, r));\r\n      \
    \  }\r\n    }\r\n    Monoid update(int a, int b, const OperatorMonoid &x) {\r\n\
    \        return update(a, b, x, 1, 0, sz);\r\n    }\r\n    Monoid query(int a,\
    \ int b, int k, int l, int r){\r\n        propagate(k, r - l);\r\n        if(r\
    \ <= a || b <= l) {\r\n            return m->M();\r\n        }else if(a <= l &&\
    \ r <= b) {\r\n            return data[k];\r\n        }else{\r\n            return\
    \ m->op(query(a, b, 2 * k + 0, l, (l + r) >> 1),\r\n                    query(a,\
    \ b, 2 * k + 1, (l + r) >> 1, r));\r\n        }\r\n    }\r\n    Monoid query(int\
    \ a, int b) {\r\n        return query(a, b, 1, 0, sz);\r\n    }\r\n    Monoid\
    \ operator[](const int &k) {\r\n        return query(k, k + 1);\r\n    }\r\n};\r\
    \nnamespace LSTOpt{\r\n    struct secadd : CmdOp{\r\n        // \u5358\u4F4D\u5143\
    \r\n        Monoid ID(){ return 0; }\r\n        // \u8981\u7D20\u3068\u4F5C\u7528\
    \u7D20\u306E\u30DE\u30FC\u30B8\r\n        Monoid mapping(Monoid a, OpMonoid b)\
    \ { return a + b; };\r\n        // \u4F5C\u7528\u7D20\u3068\u4F5C\u7528\u7D20\u306E\
    \u30DE\u30FC\u30B8\r\n        OpMonoid composition(OpMonoid a, OpMonoid b) { return\
    \ a + b; };\r\n    } ;\r\n    struct seccng : CmdOp{\r\n        // \u5358\u4F4D\
    \u5143 \u203B\u8981\u5909\u66F4\r\n        Monoid ID(){ return INF; }\r\n    \
    \    // \u8981\u7D20\u3068\u4F5C\u7528\u7D20\u306E\u30DE\u30FC\u30B8\r\n     \
    \   Monoid mapping(Monoid a, OpMonoid b) { return (b==ID())?a:b; };\r\n      \
    \  // \u4F5C\u7528\u7D20\u3068\u4F5C\u7528\u7D20\u306E\u30DE\u30FC\u30B8\r\n \
    \       OpMonoid composition(OpMonoid a, OpMonoid b) { return (b==ID())?a:b; };\r\
    \n    };\r\n    // min\r\n    struct secmin : CmdM{\r\n        // \u5358\u4F4D\
    \u5143\r\n        Monoid M(){ return INF; }\r\n        // \u6F14\u7B97\r\n   \
    \     Monoid op(Monoid a, Monoid b){ return std::min(a, b); }\r\n        // \u4F5C\
    \u7528\u7D20\u30DE\u30FC\u30B8\u306E\u524D\u306B\u304B\u307E\u305B\u308B\u95A2\
    \u6570\r\n        OpMonoid p(OpMonoid a, size_t n){ return a; }\r\n    };\r\n\
    \    // sum\r\n    struct secsum : CmdM{\r\n        // \u5358\u4F4D\u5143\r\n\
    \        Monoid M(){ return 0; }\r\n        // \u6F14\u7B97\r\n        Monoid\
    \ op(Monoid a, Monoid b){ return a+b; }\r\n        // \u4F5C\u7528\u7D20\u30DE\
    \u30FC\u30B8\u306E\u524D\u306B\u304B\u307E\u305B\u308B\u95A2\u6570\r\n       \
    \ OpMonoid p(OpMonoid a, size_t n){ return a*n; }\r\n    };\r\n};\r\n#pragma endregion\n"
  code: "// \u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\r\n#pragma region LazySegmentTree\r\
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
    \ OpMonoid p(OpMonoid a, size_t n){ return a*n; }\r\n    };\r\n};\r\n#pragma endregion"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/struct/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2021-06-18 20:18:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/struct/LazySegmentTree/RMQ_RAQ.test.cpp
  - test/struct/LazySegmentTree/RSQ_RUQ.test.cpp
  - test/struct/LazySegmentTree/RSQ_RAQ.test.cpp
  - test/struct/LazySegmentTree/RMQ_RUQ.test.cpp
documentation_of: snippet/at/struct/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/snippet/at/struct/LazySegmentTree.hpp
- /library/snippet/at/struct/LazySegmentTree.hpp.html
title: snippet/at/struct/LazySegmentTree.hpp
---
