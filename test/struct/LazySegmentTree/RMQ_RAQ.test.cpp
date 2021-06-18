#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

#include "./snippet/at/header/header.hpp"
#include "./snippet/at/struct/LazySegmentTree.hpp"

int main(){
    I(ll, N, Q);
    LST lst(N, new LSTOpt::secmin(), new LSTOpt::secadd());
    REP(i, N){
        lst.set(i, 0);
    }
    lst.build();
    REP(i, Q){
        I(ll, q);
        if(!q){
            I(ll, s, t, x);
            lst.update(s, t+1, x);
        }else{
            I(ll, s, t);
            cout << lst.query(s, t+1) << el;
        }
    }
    return 0;
}
