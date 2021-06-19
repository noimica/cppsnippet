#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include "./snippet/at/header/header.hpp"
#include "./snippet/at/graph/graph.hpp"
#include "./snippet/at/graph/LCA.hpp"

int main(){
    I(ll, N);
    graph g(N);
    REP(i, N){
        I(ll, k);
        REP(j, k){
            I(ll, c);
            g.add_edge(i, c);
        }
    }
    LCA lca(g);
    I(ll, Q);
    REP(i, Q){
        I(ll, u, v);
        cout << lca.query(u, v) << el;
    }
    return 0;
}