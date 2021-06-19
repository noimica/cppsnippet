#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_2_A"

#include "./snippet/at/header/header.hpp"
#include "./snippet/at/graph/graph.hpp"
#include "./snippet/at/graph/TSP.hpp"

int main(){
    I(ll, V, E);
    graph g(V);
    REP(i, E){
        I(ll, s, t, d);
        g.add_diedge(s, t, d);
    }
    TSP tsp(g);
    auto w = tsp.calc();
    if(w == INF){
        cout << -1 << el;
    }else{
        cout << w << el;
    }
    return 0;
}