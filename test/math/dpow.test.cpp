#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"

#include "./snippet/at/header/header.hpp"
#include "./snippet/at/math/dpow.hpp"

int main(){
    I(ll, m, n);
    cout << dpow(m, n, 1e9+7) << el;
    return 0;
}