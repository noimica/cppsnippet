#pragma region warshallFloyd
// O(|V|^3)
pair<bool, vector<vector<ll>>> warshallFloyd(const vector<vector<ll>> &_dist){
    int V = _dist.size();
    vector<vector<ll>> dist(_dist);
    REP(k, V) {
        REP(i, V) {
            REP(j, V) {
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    bool is_negative_cycle = false;
    REP(i, V){
        if(dist[i][i] < 0){
            is_negative_cycle = true;break;
        }
    }
    return {is_negative_cycle, dist};
}
pair<bool, vector<vector<ll>>> warshallFloyd(const graph& g) {
    int V = g.V;
    vector<vector<ll>> dist(V, vector<ll>(V, INF));
    REP(i, V){
        dist[i][i] = 0;
        for(auto e : g.G[i]){
            dist[i][e.to] = e.cost;
        }
    }
    return warshallFloyd(dist);
}
#pragma endregion