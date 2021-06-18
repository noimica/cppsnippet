ll dpow(ll x, ll n, int mod = __INT_MAX__) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}
