#pragma region IOMacros
template<class T>
istream &operator>>(istream &stream, vec<T>& o){REP(i, o.size())stream >> o[i];return stream;}
template<class T>
ostream &operator<<(ostream &stream, vec<T>& objs){REP(i, objs.size())stream << objs[i] << " ";stream << el;return stream;}

#define I(T, ...) ;T __VA_ARGS__;__i(__VA_ARGS__);
void __i() {}
template<class T, class... Ts> void __i(T&& o, Ts&&... args){cin >> o;__i(forward<Ts>(args)...);}

void O() {cout << el;}
template<class T, class... Ts> void O(T&& o, Ts&&... args){cerr << o << " ";O(forward<Ts>(args)...);}
#pragma endregion