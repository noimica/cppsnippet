#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B"

#include "./snippet/at/header/header.hpp"
#include "./snippet/at/graph/graph.hpp"
#include "./snippet/at/graph/bellman_ford.hpp"

int main(){
    I(ll, V, E, r);
    graph g(V);
    REP(i, E){
        I(ll, s, t, d);
        g.add_diedge(s, t, d);
    }

    auto [nc, d] = bellman_ford(g, r);
    if(nc){
        cout << "NEGATIVE CYCLE" << el;
        return 0;
    }
    REP(i, V){
        if(d.find(i) != d.end()){
            cout << d[i] << el;
        }else{
            cout << "INF" << el;
        }
    }
    return 0;
}