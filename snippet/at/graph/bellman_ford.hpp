#pragma region bellman_ford
// O(|E||V|)
pair<bool, vector<ll>> bellman_ford(int V, const vector<edge> &edges, int s){
    vector<ll> dist(V, INF);
    dist[s] = 0;
    bool is_negative_cycle = true;
    REP(cnt, V){
        bool end = true;
        for (auto e : edges) {
            if (dist[e.from] != INF && dist[e.from] + e.cost < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.cost;
                end = false;
            }
        }
        if (end){
            // ここで抜けなかったら負の閉路がある
            is_negative_cycle = false;
            break;
        }
    }
    return {is_negative_cycle, dist};
}
pair<bool, vector<ll>> bellman_ford(const graph& g, int s) {
    int V = g.V;
    vector<edge> edges;
    REP(i, V){
        for(auto e : g.G[i]){
            edges.emplace_back(e);
        }
    }
    return bellman_ford(V, edges, s);
}
#pragma endregion