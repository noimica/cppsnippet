---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/struct/modint_pow.test.cpp
    title: test/struct/modint_pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"snippet/at/struct/modint.hpp\"\n// mod P\u306E\u305F\u3081\
    \u306E\u578B\r\n#pragma region modint\r\ntemplate<ll m> struct modint{\r\nprotected:\r\
    \n    ll v=0;\r\npublic:\r\n    //\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\r\
    \n    modint(ll x=0){while(x<0)x+=m;v=x%m;}\r\n    modint(const modint &r){v=r.val();}\r\
    \n    //\u7B97\u8853\u6F14\u7B97\u5B50(\u5358\u9805)\r\n    modint operator -(){return\
    \ modint(-v);} \r\n    modint& operator ++(){if(++v>=m)v-=m; return *this;}\r\n\
    \    modint operator ++(int){modint t = *this; ++*this; return t;}\r\n    modint&\
    \ operator --(){if(--v<0)v+=m; return *this;}\r\n    modint operator --(int){modint\
    \ t = *this; --*this; return t;}\r\n    //\u7B97\u8853\u6F14\u7B97\u5B50(\u4E8C\
    \u9805)\r\n    friend modint operator +(const modint &l, const modint &r){return\
    \ modint(l)+=r;}\r\n    friend modint operator -(const modint &l, const modint\
    \ &r){return modint(l)-=r;}\r\n    friend modint operator *(const modint &l, const\
    \ modint &r){return modint(l)*=r;}\r\n    friend modint operator /(const modint\
    \ &l, const modint &r){return modint(l)/=r;}\r\n    // \u30AD\u30E3\u30B9\u30C8\
    \u6F14\u7B97\u5B50\r\n    explicit operator int() const {return val();}\r\n  \
    \  explicit operator ll() const {return val();}\r\n    //\u4EE3\u5165\u6F14\u7B97\
    \u5B50\r\n    modint &operator +=(const modint &r){\r\n        v+=r.val();\r\n\
    \        if(v>=m)v-=m;\r\n        return *this;\r\n    }\r\n    modint &operator\
    \ -=(const modint &r){\r\n        if(v<r.val())v+=m;\r\n        v-=r.val();\r\n\
    \        return *this;\r\n    }\r\n    modint &operator *=(const modint &r){\r\
    \n        v=v*r.val()%m;\r\n        return *this;\r\n    }\r\n    modint &operator\
    \ /=(const modint &r){\r\n        v=v*r.inv().val()%m;\r\n        return *this;\r\
    \n    }\r\n    //\u7B49\u4FA1\u6BD4\u8F03\u6F14\u7B97\u5B50\r\n    friend bool\
    \ operator ==(const modint &l, const modint& r){return l.val()==r.val();}\r\n\
    \    friend bool operator <(const modint &l, const modint& r){return l.val()<r.val();}\r\
    \n    friend bool operator >(const modint &l, const modint& r){return l.val()>r.val();}\r\
    \n    friend bool operator !=(const modint &l, const modint& r){return l.val()!=r.val();}\r\
    \n    // \u5404\u7A2E\u95A2\u6570\r\n    int val() const{return v;}\r\n    constexpr\
    \ static ll mod(){return m;}\r\n    static modint raw(ll x){modint r;r.v=x;return\
    \ r;}\r\n    modint inv() const{\r\n        ll a=v,b=m,u=1,v=0;\r\n        while(b){\r\
    \n            ll t=a/b;\r\n            a-=t*b;swap(a,b);\r\n            u-=t*v;swap(u,v);\r\
    \n        }\r\n        u %= m; \r\n        if (u < 0) u += m;\r\n        return\
    \ u;\r\n    }\r\n    modint pow(ll n) const{\r\n        modint ret = 1, x(v);\r\
    \n        while (n > 0) {\r\n            if (n & 1) ret *= x;\r\n            x\
    \ *= x;\r\n            n >>= 1;\r\n        }\r\n        return ret;\r\n    }\r\
    \n    //\u5165\u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\r\n    friend istream\
    \ &operator>>(istream &is,modint& x){ll t;is>>t;x=t;return (is);}\r\n    friend\
    \ ostream &operator<<(ostream &os,const modint& x){return os<<x.val();}\r\n  \
    \  \r\n};\r\nusing modint1000000007 = modint<1000000007>;\r\nusing modint998244353\
    \ = modint<998244353>;\r\n#pragma endregion\n"
  code: "// mod P\u306E\u305F\u3081\u306E\u578B\r\n#pragma region modint\r\ntemplate<ll\
    \ m> struct modint{\r\nprotected:\r\n    ll v=0;\r\npublic:\r\n    //\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\r\n    modint(ll x=0){while(x<0)x+=m;v=x%m;}\r\n\
    \    modint(const modint &r){v=r.val();}\r\n    //\u7B97\u8853\u6F14\u7B97\u5B50\
    (\u5358\u9805)\r\n    modint operator -(){return modint(-v);} \r\n    modint&\
    \ operator ++(){if(++v>=m)v-=m; return *this;}\r\n    modint operator ++(int){modint\
    \ t = *this; ++*this; return t;}\r\n    modint& operator --(){if(--v<0)v+=m; return\
    \ *this;}\r\n    modint operator --(int){modint t = *this; --*this; return t;}\r\
    \n    //\u7B97\u8853\u6F14\u7B97\u5B50(\u4E8C\u9805)\r\n    friend modint operator\
    \ +(const modint &l, const modint &r){return modint(l)+=r;}\r\n    friend modint\
    \ operator -(const modint &l, const modint &r){return modint(l)-=r;}\r\n    friend\
    \ modint operator *(const modint &l, const modint &r){return modint(l)*=r;}\r\n\
    \    friend modint operator /(const modint &l, const modint &r){return modint(l)/=r;}\r\
    \n    // \u30AD\u30E3\u30B9\u30C8\u6F14\u7B97\u5B50\r\n    explicit operator int()\
    \ const {return val();}\r\n    explicit operator ll() const {return val();}\r\n\
    \    //\u4EE3\u5165\u6F14\u7B97\u5B50\r\n    modint &operator +=(const modint\
    \ &r){\r\n        v+=r.val();\r\n        if(v>=m)v-=m;\r\n        return *this;\r\
    \n    }\r\n    modint &operator -=(const modint &r){\r\n        if(v<r.val())v+=m;\r\
    \n        v-=r.val();\r\n        return *this;\r\n    }\r\n    modint &operator\
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
    \ endregion"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/struct/modint.hpp
  requiredBy: []
  timestamp: '2021-06-18 20:18:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/struct/modint_pow.test.cpp
documentation_of: snippet/at/struct/modint.hpp
layout: document
redirect_from:
- /library/snippet/at/struct/modint.hpp
- /library/snippet/at/struct/modint.hpp.html
title: snippet/at/struct/modint.hpp
---
