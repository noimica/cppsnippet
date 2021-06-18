#pragma region warshall_floyd
// O(|V|^3)
vector<vector<ll>> warshall_floyd(const vector<vector<ll>> &_dist){
    int V = _dist.size();
    vector<vector<ll>> dist(_dist);
    REP(k, V) {
        REP(i, V) {
            REP(j, V) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}
vector<vector<ll>> warshall_floyd(const graph& g) {
    int V = g.V;
    vector<vector<ll>> dist(V, vector<ll>(V, INF));
    REP(i, V){
        dist[i][i] = 0;
        for(auto e : g.G[i]){
            dist[i][e.to] = e.cost;
        }
    }
    return warshall_floyd(dist);
}
#pragma endregion