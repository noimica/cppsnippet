#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"

#include "./snippet/at/header/header.hpp"
#include "./snippet/at/struct/modint.hpp"

using mint = modint1000000007;

int main(){
    I(ll, m, n);
    mint ans = mint::raw(m).pow(n);
    cout << ans << el;
    return 0;
}