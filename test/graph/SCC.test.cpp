#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

#include "./snippet/at/header/header.hpp"
#include "./snippet/at/graph/graph.hpp"
#include "./snippet/at/graph/SCC.hpp"

int main(){
    I(ll, V, E);
    graph g(V);
    REP(i, E){
        I(ll, s, t);
        g.add_diedge(s, t);
    }

    SCC scc(g);
    scc.build();

    I(ll, Q);
    REP(i, Q){
        I(ll, u, v);
        auto w = scc.same(u, v);
        cout << w << el;
    }
    return 0;
}