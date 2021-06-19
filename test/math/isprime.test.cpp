#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C"

#include "./snippet/at/header/header.hpp"
#include "./snippet/at/math/dpow.hpp"
#include "./snippet/at/math/prime/isprime.hpp"

int main(){
    I(ll, N);
    ll cnt = 0;
    REP(i, N){
        I(ll, M);
        if(isprime(M)){
            cnt++;
        }
    }
    cout << cnt << el;
    return 0;
}