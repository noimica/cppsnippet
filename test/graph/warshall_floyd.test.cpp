#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C"

#include "./snippet/at/header/header.hpp"
#include "./snippet/at/graph/graph.hpp"
#include "./snippet/at/graph/warshall_floyd.hpp"

int main(){
    I(ll, V, E);
    graph g(V);
    REP(i, E){
        I(ll, s, t, d);
        g.add_diedge(s, t, d);
    }

    auto [nc, d] = warshall_floyd(g);
    if(nc){
        cout << "NEGATIVE CYCLE" << el;
        return 0;
    }
    REP(i, V){
        REP(j, V){
            if(j > 0){
                cout << " ";
            }
            if(d[i][j] != INF){
                cout << d[i][j];
            }else{
                cout << "INF";
            }
        }
        cout << el;
    }
    return 0;
}