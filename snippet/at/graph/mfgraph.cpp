#pragma region mfgraph
struct mfedge{
    ll from, to, cost, rev;
    bool operator<(const mfedge& r) const{return cost<r.cost;}
    bool operator>(const mfedge& r) const{return cost>r.cost;}
};
struct mfgraph{
    vl level;
    vl iter;
    ll V;
    vector<vector<mfedge> > G;
    mfgraph(ll n){
        init(n);
    }
    void init(ll n){
        V = n;
        G.resize(V);
        iter.resize(V);
        level.resize(V);
    }
    // 無向グラフ
    void add_edge(ll s, ll t, ll cost = 1){
        add_diedge(s, t, cost);
        add_diedge(t, s, cost);
    }
    // 有向グラフ
    void add_diedge(ll s, ll t, ll cost = 1){
        if(s < 0 || t < 0 || s >= V || t >= V) return;
        mfedge e1({s, t, cost, (ll)G[t].size()});
        mfedge e2({t, s, 0, (ll)G[s].size()});
        G[s].push_back(e1);
        G[t].push_back(e2);
    }
    //calculate min Distance from start with BFS
    void bfs(int s){
        fill(ALL(level), -1);
        queue<int> que;
        level[s]=0;
        que.push(s);
        while (!que.empty()){
            int v = que.front(); que.pop();
            REP(i, G[v].size()){
                mfedge &e = G[v][i];
                if (e.cost > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    //find path with DFS
    int dfs(ll v, ll t, ll f){
        if (v==t) return f;

        for (ll &i = iter[v]; i < G[v].size() ; i++){
            mfedge &e = G[v][i];

            if (e.cost > 0 && level[v] < level[e.to]){
                //do not search for the edge which goes back
                
                int d = dfs(e.to, t, min(f, e.cost));
                if(d > 0){
                    e.cost -= d;
                    G[e.to][e.rev].cost += d;
                    return d;
                }
            }
        }
        return 0;
    }
    ll max_flow(int s, int t){
        ll flow = 0;
        while(1){
            bfs(s);
            if(level[t] < 0) return flow;
            fill(ALL(iter), 0);
            ll f;
            while ((f = dfs(s, t, INF)) > 0 ){
                flow += f;
            }
        }
    }
    auto pos2d(ll height, ll width){
        return [height, width](ll y, ll x){
            return 
                (y < 0 || y >= height || x < 0 || x >= width)
                ? -1
                : y*width + x;
        };
    }
};
#pragma endregion