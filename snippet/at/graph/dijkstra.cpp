// O(|E|log|V|)
vector<ll> dijkstra(const graph& g, ll s){
    vector<ll> d(g.V, INF);
    d[s] = 0;
    priority_queue<P,vector<P>, greater<P>> que;
    que.push({0, s});
    while(!que.empty()){
        auto [c, v] = que.top(); que.pop();
        if(d[v]<c) continue;
        for(auto e : g.G[v]){
            if(d[e.to]>d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                que.push({d[e.to],e.to});
            }
        }
    }
    return d;
}