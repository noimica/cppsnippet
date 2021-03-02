struct travelingSalesman{
    int V;
    vector<vector<ll>> dist, dp;
    travelingSalesman(graph& _g): V(_g.V), dist(_g.V, vector<ll>(_g.V, INF)), dp(1<<_g.V, vector<ll>(_g.V, -1)){
        REP(i, V){
            EACH(e, _g.G[i]){
                dist[e.from][e.to] = e.cost;
            }
        }
    }
    ll calc(){return calc(0, 0);}
    ll calc(int s, int v){
        if(dp[s][v] >= 0){
            return dp[s][v];
        }

        if(s == (1<<V)-1 && v == 0){
            return dp[s][v] = 0;
        }

        ll ans = INF;
        REP(u, V){
            if(!(s >> u & 1)){
                ans = min(ans, calc(s | 1 << u, u) + dist[v][u]);
            }
        }

        dp[s][v] = ans;
        return ans;
    }
};