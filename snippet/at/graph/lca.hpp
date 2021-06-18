// 最小共通祖先
// 前処理 O(NlogN), クエリ O(logN)
struct LCA {
    vector<vector<int>> parent;  // parent[k][u]:= u の 2^k 先の親
    vector<int> dist;            // root からの距離
    LCA(const graph &g, int root = 0) { init(g, root); }
    // 初期化
    void init(const graph &g, int root = 0) {
        ll V = g.V;
        ll K = __builtin_popcountll(LONG_LONG_MAX) - __builtin_clzll(V) + 1;
        parent.assign(K, vector<int>(V, -1));
        dist.assign(V, -1);
        dfs(g, root, -1, 0);
        for (int k = 0; k + 1 < K; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }
    // 根からの距離と1つ先の頂点を求める
    void dfs(const graph &g, int v, int p, int d) {
        parent[0][v] = p;
        dist[v] = d;
        for (auto e : g.G[v]) {
            if (e.to != p) dfs(g, e.to, v, d + 1);
        }
    }
    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);  // u の方が深いとする
        int K = parent.size();
        // LCA までの距離を同じにする
        for (int k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        // 二分探索で LCA を求める
        if (u == v) return u;
        for (int k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};