#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A"

#include "./snippet/at/header/header.hpp"
#include "./snippet/at/graph/graph.hpp"
#include "./snippet/at/graph/dijkstra.hpp"

int main(){
    I(ll, V, E, r);
    graph g(V);
    REP(i, E){
        I(ll, s, t, d);
        g.add_diedge(s, t, d);
    }

    auto d = dijkstra(g, r);
    REP(i, V){
        if(d.find(i) != d.end()){
            cout << d[i] << el;
        }else{
            cout << "INF" << el;
        }
    }
    return 0;
}