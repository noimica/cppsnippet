---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snippet/at/header/header.hpp
    title: snippet/at/header/header.hpp
  - icon: ':heavy_check_mark:'
    path: snippet/at/struct/UnionFind.hpp
    title: "\u30C7\u30FC\u30BFx\u306E\u5C5E\u3059\u308B\u6728\u306E\u6839\u3092\u53D6\
      \u5F97(\u7D4C\u8DEF\u5727\u7E2E\u3082\u884C\u3046)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/struct/UnionFind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
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
    #pragma endregion\r\n#line 1 \"snippet/at/struct/UnionFind.hpp\"\n#pragma region\
    \ UnionFind\r\n// https://qiita.com/DaikiSuyama/items/444e409423bd1b4b83d7\r\n\
    class UnionFind{\r\npublic:\r\n    vector<ll> parent; //parent[i]\u306Fi\u306E\
    \u89AA\r\n    vector<ll> siz; //\u7D20\u96C6\u5408\u306E\u30B5\u30A4\u30BA\u3092\
    \u8868\u3059\u914D\u5217(1\u3067\u521D\u671F\u5316)\r\n    umap<ll,vector<ll>>\
    \ group; //\u96C6\u5408\u3054\u3068\u306B\u7BA1\u7406\u3059\u308B(key:\u96C6\u5408\
    \u306E\u4EE3\u8868\u5143\u3001value:\u96C6\u5408\u306E\u8981\u7D20\u306E\u914D\
    \u5217)\r\n    ll n; //\u8981\u7D20\u6570\r\n    UnionFind(ll n_):n(n_),parent(n_),siz(n_,1){\
    \ \r\n        //\u5168\u3066\u306E\u8981\u7D20\u306E\u6839\u304C\u81EA\u8EAB\u3067\
    \u3042\u308B\u3068\u3057\u3066\u521D\u671F\u5316\r\n        for(ll i=0;i<n;i++){parent[i]=i;}\r\
    \n    }\r\n    //!@brief \u30C7\u30FC\u30BFx\u306E\u5C5E\u3059\u308B\u6728\u306E\
    \u6839\u3092\u53D6\u5F97(\u7D4C\u8DEF\u5727\u7E2E\u3082\u884C\u3046)\r\n    ll\
    \ root(ll x){\r\n        if(parent[x]==x) return x;\r\n        return parent[x]=root(parent[x]);//\u4EE3\
    \u5165\u5F0F\u306E\u5024\u306F\u4EE3\u5165\u3057\u305F\u5909\u6570\u306E\u5024\
    \u306A\u306E\u3067\u3001\u7D4C\u8DEF\u5727\u7E2E\u3067\u304D\u308B\r\n    }\r\n\
    \    //!@brief x\u3068y\u306E\u6728\u3092\u4F75\u5408\r\n    void unite(ll x,ll\
    \ y){\r\n        ll rx=root(x);//x\u306E\u6839\r\n        ll ry=root(y);//y\u306E\
    \u6839\r\n        if(rx==ry) return;//\u540C\u3058\u6728\u306B\u3042\u308B\u6642\
    \r\n        //\u5C0F\u3055\u3044\u96C6\u5408\u3092\u5927\u304D\u3044\u96C6\u5408\
    \u3078\u3068\u4F75\u5408(ry\u2192rx\u3078\u4F75\u5408)\r\n        if(siz[rx]<siz[ry])\
    \ swap(rx,ry);\r\n        siz[rx]+=siz[ry];\r\n        parent[ry]=rx;//x\u3068\
    y\u304C\u540C\u3058\u6728\u306B\u306A\u3044\u6642\u306Fy\u306E\u6839ry\u3092x\u306E\
    \u6839rx\u306B\u3064\u3051\u308B\r\n    }\r\n    //!@brief x\u3068y\u304C\u5C5E\
    \u3059\u308B\u6728\u304C\u540C\u3058\u304B\u3092\u5224\u5B9A\r\n    bool same(ll\
    \ x,ll y){\r\n        ll rx=root(x);\r\n        ll ry=root(y);\r\n        return\
    \ rx==ry;\r\n    }\r\n    //!@brief x\u306E\u7D20\u96C6\u5408\u306E\u30B5\u30A4\
    \u30BA\u3092\u53D6\u5F97\r\n    ll size(ll x){\r\n        return siz[root(x)];\r\
    \n    }\r\n    //!@brief \u7D20\u96C6\u5408\u3092\u305D\u308C\u305E\u308C\u30B0\
    \u30EB\u30FC\u30D7\u5316\r\n    void grouping(){\r\n        //\u7D4C\u8DEF\u5727\
    \u7E2E\u3092\u5148\u306B\u884C\u3046\r\n        REP(i,n)root(i);\r\n        //map\u3067\
    \u7BA1\u7406\u3059\u308B(\u30C7\u30D5\u30A9\u30EB\u30C8\u69CB\u7BC9\u3092\u5229\
    \u7528)\r\n        REP(i,n)group[parent[i]].push_back(i);\r\n    }\r\n    //!@brief\
    \ \u7D20\u96C6\u5408\u7CFB\u3092\u524A\u9664\u3057\u3066\u521D\u671F\u5316\r\n\
    \    void clear(){\r\n        REP(i,n){parent[i]=i;}\r\n        siz=vector<ll>(n,1);\r\
    \n        group.clear();\r\n    }\r\n};\r\n#pragma endregion\n#line 5 \"test/struct/UnionFind.test.cpp\"\
    \n\r\nint main(){\r\n    I(ll, N, Q);\r\n    UnionFind uf(N);\r\n    REP(i, Q){\r\
    \n        I(ll, t, u, v);\r\n        if(!t){\r\n            uf.unite(u, v);\r\n\
    \        }else{\r\n            cout << uf.same(u, v) << el;\r\n        }\r\n \
    \   }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\r\n\r\n#include\
    \ \"./snippet/at/header/header.hpp\"\r\n#include \"./snippet/at/struct/UnionFind.hpp\"\
    \r\n\r\nint main(){\r\n    I(ll, N, Q);\r\n    UnionFind uf(N);\r\n    REP(i,\
    \ Q){\r\n        I(ll, t, u, v);\r\n        if(!t){\r\n            uf.unite(u,\
    \ v);\r\n        }else{\r\n            cout << uf.same(u, v) << el;\r\n      \
    \  }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - snippet/at/header/header.hpp
  - snippet/at/struct/UnionFind.hpp
  isVerificationFile: true
  path: test/struct/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2021-06-18 18:22:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/struct/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/struct/UnionFind.test.cpp
- /verify/test/struct/UnionFind.test.cpp.html
title: test/struct/UnionFind.test.cpp
---
