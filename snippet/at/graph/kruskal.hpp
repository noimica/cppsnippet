#pragma region kruskal
pair<ll, graph> kruskal(ll V, vector<edge>& edges, ll K = 0){
    UnionFind uf(V);
    graph r(V);
    sort(edges.begin(), edges.end());
    ll sum = 0;
    EACH(e, edges){
        if(K <= 0) break;
        auto [f, t, c] = e;
        if(uf.same(f, t)) continue;
        r.add_edge(f, t, c);
        uf.unite(f, t);
        sum += c;
        K--;
    }
    return {sum, r};
}

pair<ll, graph> kruskal(const graph& g, ll K = 0){
    vector<edge> edges;
    K = g.V - K; // 張る辺の最大値
    REP(i, g.V){
        EACH(e, g.G[i]){
            if(e.to <= i) continue;
            edges.push_back(e);
        }
    }
    return kruskal(g.V, edges, K);
}
#pragma endregion