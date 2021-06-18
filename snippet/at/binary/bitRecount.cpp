namespace bit{
    template <class Func>
    void recount(ll n, Func f){
        for(int i=0; n>0; ++i, n>>=1){
            if(n&1) f(i);
        }
    }
    // 全体のbit数 何bit立たせるか
    ll start(ll bit, ll n){
        return ((1<<n)-1)<<(bit-n);
    }
    ll next(ll _x){
        constexpr int llbit = __builtin_clzll(1)+1;
        if((1<<__builtin_popcountll(_x))-1 == _x) return 0;
        ll x = _x;
        ll r1 = __builtin_ctzll(x);
        if(r1 > 0){ // 繰り上げの必要なし
            ll t = 1ll<<r1;
            return (_x&~t) | (t>>1);
        }
        x >>= r1;
        ll r2 = __builtin_ctzll(~x);
        x >>= r2;
        ll r3 = __builtin_ctzll(x);
        x >>= r3;
        // 繰り上げの必要がある
        return ((x^1)<<(r2+r3)) | start(r2+r3, r2+1);
    }
}