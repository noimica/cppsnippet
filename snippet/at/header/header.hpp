#pragma region Macros
#include <bits/stdc++.h>
#if defined(LOCAL) || defined(ONLINE_JUDGE) || defined(_DEBUG)
#include <atcoder/all>
#endif
using namespace std;
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i, n) for(int i=(n); i>=0; --i)
#define FOR(i, n, m) for(int i=(m), i##_len=(n); i<i##_len; ++i)
#define EACH(i, v) for(const auto& i : v)
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>using vec = vector<T>;
template<class T, class U>using umap = unordered_map<T, U>;
template<class T>using uset = unordered_set<T>;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
//using T = tuple<ll, ll, ll>;
using vl = vec<ll>;
#define fi first
#define se second
#define el endl
constexpr ll INF = numeric_limits<ll>::max()/2-1;
#pragma endregion

#pragma region IOMacros
template<class T>
istream &operator>>(istream &stream, vec<T>& o){REP(i, o.size())stream >> o[i];return stream;}
template<class T>
ostream &operator<<(ostream &stream, vec<T>& objs){REP(i, objs.size())stream << objs[i] << " ";stream << el;return stream;}

#define I(T, ...) ;T __VA_ARGS__;__i(__VA_ARGS__);
void __i() {}
template<class T, class... Ts> void __i(T&& o, Ts&&... args){cin >> o;__i(forward<Ts>(args)...);}

#ifdef LOCAL
void O() {cerr << el;}
template<class T, class... Ts> void O(T&& o, Ts&&... args){cerr << o << " ";O(forward<Ts>(args)...);}
#else
template<class T, class... Ts> void O(T&& o, Ts&&... args){};
#endif
#pragma endregion
