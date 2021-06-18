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
  bundledCode: "#line 1 \"snippet/at/header/IO.hpp\"\n#pragma region IOMacros\r\n\
    template<class T>\r\nistream &operator>>(istream &stream, vec<T>& o){REP(i, o.size())stream\
    \ >> o[i];return stream;}\r\ntemplate<class T>\r\nostream &operator<<(ostream\
    \ &stream, vec<T>& objs){REP(i, objs.size())stream << objs[i] << \" \";stream\
    \ << el;return stream;}\r\n\r\n#define I(T, ...) ;T __VA_ARGS__;__i(__VA_ARGS__);\r\
    \nvoid __i() {}\r\ntemplate<class T, class... Ts> void __i(T&& o, Ts&&... args){cin\
    \ >> o;__i(forward<Ts>(args)...);}\r\n\r\nvoid O() {cout << el;}\r\ntemplate<class\
    \ T, class... Ts> void O(T&& o, Ts&&... args){cerr << o << \" \";O(forward<Ts>(args)...);}\r\
    \n#pragma endregion\n"
  code: "#pragma region IOMacros\r\ntemplate<class T>\r\nistream &operator>>(istream\
    \ &stream, vec<T>& o){REP(i, o.size())stream >> o[i];return stream;}\r\ntemplate<class\
    \ T>\r\nostream &operator<<(ostream &stream, vec<T>& objs){REP(i, objs.size())stream\
    \ << objs[i] << \" \";stream << el;return stream;}\r\n\r\n#define I(T, ...) ;T\
    \ __VA_ARGS__;__i(__VA_ARGS__);\r\nvoid __i() {}\r\ntemplate<class T, class...\
    \ Ts> void __i(T&& o, Ts&&... args){cin >> o;__i(forward<Ts>(args)...);}\r\n\r\
    \nvoid O() {cout << el;}\r\ntemplate<class T, class... Ts> void O(T&& o, Ts&&...\
    \ args){cerr << o << \" \";O(forward<Ts>(args)...);}\r\n#pragma endregion"
  dependsOn: []
  isVerificationFile: false
  path: snippet/at/header/IO.hpp
  requiredBy: []
  timestamp: '2021-06-18 15:56:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/at/header/IO.hpp
layout: document
redirect_from:
- /library/snippet/at/header/IO.hpp
- /library/snippet/at/header/IO.hpp.html
title: snippet/at/header/IO.hpp
---
