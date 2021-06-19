#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include "./snippet/at/header/header.hpp"
#include "./snippet/at/graph/mfgraph.hpp"

int main(){
    I(ll, V, E);
    mfgraph g(V);
    REP(i, E){
        I(ll, s, t, d);
        g.add_diedge(s, t, d);
    }
    ll w = g.max_flow(0, V-1);
    cout << w << el;
    return 0;
}