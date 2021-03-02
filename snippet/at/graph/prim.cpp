pair<ll, graph> prim(const graph& g){
    graph r(g.V);
    priority_queue<edge, vector<edge>, greater<edge>> que;
    que.push({-1, 0, 0});
    ll sum = 0;
    while(!que.empty()){
        auto [f, t, c] = que.top(); que.pop();
        if(r.G[t].size() > 0) continue;
        if(f != -1) r.add_edge(f, t, c);
        sum += c;
        for(auto& e: g.G[t]){
            if(r.G[e.to].size() > 0) continue;
            que.push(e);
        }
    }
    return {sum, r};
}