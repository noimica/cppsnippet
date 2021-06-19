// O(V+E)
umap<ll, ll> BFS(const graph& g, ll s, ll limit = INF){
    vector<ll> d(g.V, INF);
    umap<ll, ll> ret;
    d[s] = 0;
    queue<P> que;
    que.push({0, s});
    ret[s] = 0;
    while(!que.empty()){
        auto [c, v] = que.front(); que.pop();
        if(d[v]<c) continue;
        for(auto e : g.G[v]){
            ll l = d[v]+e.cost;
            if(d[e.to]>l && limit>=l){
                d[e.to] = l;
                que.push({d[e.to],e.to});
                ret[e.to] = d[e.to];
            }
        }
    }
    return ret;
}