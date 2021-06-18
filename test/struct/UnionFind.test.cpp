#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "./snippet/at/header/header.cpp"
#include "./snippet/at/struct/UnionFind.cpp"

int main(){
    I(ll, N, Q);
    UnionFind uf(N);
    REP(i, Q){
        I(ll, t, u, v);
        if(!t){
            uf.unite(u, v);
        }else{
            cout << uf.same(u, v) << el;
        }
    }
    return 0;
}