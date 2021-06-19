---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: snippet/at/header/header.hpp
    title: snippet/at/header/header.hpp
  - icon: ':heavy_check_mark:'
    path: snippet/at/struct/modint.hpp
    title: snippet/at/struct/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
  bundledCode: "#line 1 \"test/struct/modint_pow.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
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
    #pragma endregion\r\n#line 1 \"snippet/at/struct/modint.hpp\"\n// mod P\u306E\u305F\
    \u3081\u306E\u578B\r\n#pragma region modint\r\ntemplate<ll m> struct modint{\r\
    \nprotected:\r\n    ll v=0;\r\npublic:\r\n    //\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\r\n    modint(ll x=0){while(x<0)x+=m;v=x%m;}\r\n    modint(const\
    \ modint &r){v=r.val();}\r\n    //\u7B97\u8853\u6F14\u7B97\u5B50(\u5358\u9805\
    )\r\n    modint operator -(){return modint(-v);} \r\n    modint& operator ++(){if(++v>=m)v-=m;\
    \ return *this;}\r\n    modint operator ++(int){modint t = *this; ++*this; return\
    \ t;}\r\n    modint& operator --(){if(--v<0)v+=m; return *this;}\r\n    modint\
    \ operator --(int){modint t = *this; --*this; return t;}\r\n    //\u7B97\u8853\
    \u6F14\u7B97\u5B50(\u4E8C\u9805)\r\n    friend modint operator +(const modint\
    \ &l, const modint &r){return modint(l)+=r;}\r\n    friend modint operator -(const\
    \ modint &l, const modint &r){return modint(l)-=r;}\r\n    friend modint operator\
    \ *(const modint &l, const modint &r){return modint(l)*=r;}\r\n    friend modint\
    \ operator /(const modint &l, const modint &r){return modint(l)/=r;}\r\n    //\
    \ \u30AD\u30E3\u30B9\u30C8\u6F14\u7B97\u5B50\r\n    explicit operator int() const\
    \ {return val();}\r\n    explicit operator ll() const {return val();}\r\n    //\u4EE3\
    \u5165\u6F14\u7B97\u5B50\r\n    modint &operator +=(const modint &r){\r\n    \
    \    v+=r.val();\r\n        if(v>=m)v-=m;\r\n        return *this;\r\n    }\r\n\
    \    modint &operator -=(const modint &r){\r\n        if(v<r.val())v+=m;\r\n \
    \       v-=r.val();\r\n        return *this;\r\n    }\r\n    modint &operator\
    \ *=(const modint &r){\r\n        v=v*r.val()%m;\r\n        return *this;\r\n\
    \    }\r\n    modint &operator /=(const modint &r){\r\n        v=v*r.inv().val()%m;\r\
    \n        return *this;\r\n    }\r\n    //\u7B49\u4FA1\u6BD4\u8F03\u6F14\u7B97\
    \u5B50\r\n    friend bool operator ==(const modint &l, const modint& r){return\
    \ l.val()==r.val();}\r\n    friend bool operator <(const modint &l, const modint&\
    \ r){return l.val()<r.val();}\r\n    friend bool operator >(const modint &l, const\
    \ modint& r){return l.val()>r.val();}\r\n    friend bool operator !=(const modint\
    \ &l, const modint& r){return l.val()!=r.val();}\r\n    // \u5404\u7A2E\u95A2\u6570\
    \r\n    int val() const{return v;}\r\n    constexpr static ll mod(){return m;}\r\
    \n    static modint raw(ll x){modint r;r.v=x;return r;}\r\n    modint inv() const{\r\
    \n        ll a=v,b=m,u=1,v=0;\r\n        while(b){\r\n            ll t=a/b;\r\n\
    \            a-=t*b;swap(a,b);\r\n            u-=t*v;swap(u,v);\r\n        }\r\
    \n        u %= m; \r\n        if (u < 0) u += m;\r\n        return u;\r\n    }\r\
    \n    modint pow(ll n) const{\r\n        modint ret = 1, x(v);\r\n        while\
    \ (n > 0) {\r\n            if (n & 1) ret *= x;\r\n            x *= x;\r\n   \
    \         n >>= 1;\r\n        }\r\n        return ret;\r\n    }\r\n    //\u5165\
    \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\r\n    friend istream &operator>>(istream\
    \ &is,modint& x){ll t;is>>t;x=t;return (is);}\r\n    friend ostream &operator<<(ostream\
    \ &os,const modint& x){return os<<x.val();}\r\n    \r\n};\r\nusing modint1000000007\
    \ = modint<1000000007>;\r\nusing modint998244353 = modint<998244353>;\r\n#pragma\
    \ endregion\n#line 5 \"test/struct/modint_pow.test.cpp\"\n\r\nusing mint = modint1000000007;\r\
    \n\r\nint main(){\r\n    I(ll, m, n);\r\n    mint ans = mint::raw(m).pow(n);\r\
    \n    cout << ans << el;\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \r\n\r\n#include \"./snippet/at/header/header.hpp\"\r\n#include \"./snippet/at/struct/modint.hpp\"\
    \r\n\r\nusing mint = modint1000000007;\r\n\r\nint main(){\r\n    I(ll, m, n);\r\
    \n    mint ans = mint::raw(m).pow(n);\r\n    cout << ans << el;\r\n    return\
    \ 0;\r\n}"
  dependsOn:
  - snippet/at/header/header.hpp
  - snippet/at/struct/modint.hpp
  isVerificationFile: true
  path: test/struct/modint_pow.test.cpp
  requiredBy: []
  timestamp: '2021-06-19 19:28:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/struct/modint_pow.test.cpp
layout: document
redirect_from:
- /verify/test/struct/modint_pow.test.cpp
- /verify/test/struct/modint_pow.test.cpp.html
title: test/struct/modint_pow.test.cpp
---
