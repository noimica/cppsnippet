#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"

#include "./snippet/at/header/header.hpp"
#include "./snippet/at/graph/graph.hpp"
#include "./snippet/at/graph/BFS.hpp"
#include "./snippet/at/graph/treeDiamiter.hpp"

int main(){
    I(ll, V);
    graph g(V);
    REP(i, V-1){
        I(ll, s, t, d);
        g.add_edge(s, t, d);
    }

    auto l = treeDiamiter(g);
    cout << l << el;
    return 0;
}