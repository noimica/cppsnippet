struct Compress1D{
    map<ll, ll> V;
    Compress1D(){
        V[INF] = V[-INF] = 0;
    }
    void add(ll x, ll val){
        V[x] += val;
    }
    // [l, r]
    void addrange(ll l, ll r, ll val){
        add(l, val);
        add(r+1, -val);
    }
    void imos(){
        ll now = 0;
        for(auto &&p : V){
            now += p.se;
            p.se = now;
        }
    }
    ll get(ll x){
        return V.lower_bound(x)->second;
    }
};