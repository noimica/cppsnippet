//木の直径を求める
ll treeDiamiter(const graph& g){
    auto u=BFS(g, 0);
    ll mx=0;
    EACH(x, u){
        if(u[mx]<x.se){
            mx=x.fi;
        }
    }
    auto v=BFS(g, mx);
    EACH(x, v){
        if(v[mx]<x.se){
            mx=x.fi;
        }
    }
    return v[mx];
}