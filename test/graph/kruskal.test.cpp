#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A"

#include "./snippet/at/header/header.hpp"
#include "./snippet/at/graph/graph.hpp"
#include "./snippet/at/struct/UnionFind.hpp"
#include "./snippet/at/graph/kruskal.hpp"

int main(){
    I(ll, V, E);
    graph g(V);
    REP(i, E){
        I(ll, s, t, d);
        g.add_edge(s, t, d);
    }

    auto [w, dg] = kruskal(g);
    cout << w << el;
    return 0;
}