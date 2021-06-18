#pragma region bellmanFord
// O(|E||V|)
pair<bool, umap<ll, ll>> bellmanFord(int V, const vector<edge> &edges, int s){
    vector<ll> dist(V, INF);
    umap<ll, ll> ret;
    ret[s] = dist[s] = 0;
    bool is_negative_cycle = true;
    REP(cnt, V){
        bool end = true;
        for (auto e : edges) {
            if (dist[e.from] != INF && dist[e.from] + e.cost < dist[e.to]) {
                ret[e.to] = dist[e.to] = dist[e.from] + e.cost;
                end = false;
            }
        }
        if (end){
            // ここで抜けなかったら負の閉路がある
            is_negative_cycle = false;
            break;
        }
    }
    return {is_negative_cycle, ret};
}
pair<bool, umap<ll, ll>> bellmanFord(const graph& g, int s) {
    int V = g.V;
    vector<edge> edges;
    REP(i, V){
        for(auto e : g.G[i]){
            edges.emplace_back(e);
        }
    }
    return bellmanFord(V, edges, s);
}
#pragma endregion