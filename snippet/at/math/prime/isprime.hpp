#pragma region isprime
// O(log(N)^2) dpowが必要
// 補助関数
using ull = unsigned long long;
vec<uint> checklist(ull n){
    if(n < 2047)                return {2};
    if(n < 9080191)             return {31, 73};
    if(n < 4759123141)          return {2, 7, 61};
    if(n < 1122004669633)       return {2, 13, 23, 1662803};
    if(n < 2152302898747)       return {2, 3, 5, 7, 11};
    if(n < 3474749660383)       return {2, 3, 5, 7, 11, 13};
    if(n < 341550071728321)     return {2, 3, 5, 7, 11, 13, 17};
    if(n < 3825123056546413051) return {2, 3, 5, 7, 11, 13, 17, 19, 23};
    return {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
}
bool suspect(uint a, ull t, ull n){
    ll x = dpow(a, t, n);
    ll n1 = n - 1;
    while(t != n1 && x != 1 && x != n1){
        x = x * x % n;
        t <<= 1;
    }
    return (t & 1) || x == n1;
}
bool isprime_(ull n){
    if(n == 2) return true;
    if(n < 2 || (n & 1) == 0) return false;
    ull d = (n - 1) >> 1;
    d >>= __builtin_ctzll(d);
    // チェックリスト作成
    for(auto i : checklist(n)){
        if(i >= n) break;
        if(!suspect(i, d, n)){
            return false;
        }
    }
    return true;
}
#pragma endregion
