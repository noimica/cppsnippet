#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"

#include "./snippet/at/header/header.hpp"
#include "./snippet/at/math/prime/primeFactorize.hpp"

int main(){
    I(ll, N);
    auto pf = primeFactorize(N);
    cout << N << ":";
    EACH(v, pf){
        REP(i, v.se){
            cout << " " << v.fi;
        }
    }
    cout << el;
    return 0;
}