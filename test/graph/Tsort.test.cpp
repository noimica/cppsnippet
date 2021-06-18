// 答えが複数あるが、ローカルジャッジが対応していないのでNG
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"

#include "./snippet/at/header/header.hpp"
#include "./snippet/at/graph/graph.hpp"
#include "./snippet/at/graph/tSort.hpp"

int main(){
    I(ll, V, E);
    graph g(V);
    REP(i, E){
        I(ll, s, t);
        g.add_diedge(s, t);
    }

    auto vs = tSort(g);
    REP(i, V){
        cout << vs[i] << el;
    }
    return 0;
}