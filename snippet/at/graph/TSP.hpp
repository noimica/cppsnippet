// 巡回セールスマン問題(N^2 2^N)
struct TSP{
    int V;
    vector<vector<ll>> dist, dp;
    TSP(graph& _g): V(_g.V), dist(_g.V, vector<ll>(_g.V, INF)), dp(1<<_g.V, vector<ll>(_g.V, -1)){
        REP(i, V){
            EACH(e, _g.G[i]){
                dist[e.from][e.to] = e.cost;
            }
        }
    }
    ll calc(){return calc(0);}
    ll calc(int v){return calc(v, 0);}
    ll calc(int v, int s){
        // dp[bit][開始頂点∈bit]
        if(dp[s][v] >= 0){
            return dp[s][v];
        }

        if(s == (1<<V)-1 && v == 0){
            return dp[s][v] = 0;
        }

        ll ans = INF;
        REP(u, V){
            if(!(s&1ll<<u)){
                ans = min(ans, calc(u, s|(1<<u)) + dist[v][u]);
            }
        }

        return dp[s][v] = ans;
    }
};