#pragma region graph
struct edge{
    ll from, to, cost;
    bool operator<(const edge& r) const{return cost<r.cost;}
    bool operator>(const edge& r) const{return cost>r.cost;}
};
struct graph{
    ll V;
    vector<vector<edge> > G;
    graph(ll n){
        init(n);
    }
    void init(ll n){
        V = n;
        G.resize(V);
    }
    // 無向グラフ
    void add_edge(ll s, ll t, ll cost = 1){
        add_diedge(s, t, cost);
        add_diedge(t, s, cost);
    }
    // 有向グラフ
    void add_diedge(ll s, ll t, ll cost = 1){
        edge e;
        e.from = s, e.to = t, e.cost = cost;
        G[s].push_back(e);
    }
};
#pragma endregion