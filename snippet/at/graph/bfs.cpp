// O(V+E)
umap<ll, ll> bfs(const graph& g, ll s, ll limit = INF){
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
            if(d[e.to]>d[v]+1 && limit>=d[v]+1){
                d[e.to] = d[v]+1;
                que.push({d[e.to],e.to});
                ret[e.to] = d[e.to];
            }
        }
    }
    return ret;
}