#pragma region combn
// nCrを求める
// 前処理 O(n)
// クエリ O(1)
template <class MINT>
struct combination {
    vector<MINT> fact, ifact;
    combination(int n):fact(n+1),ifact(n+1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    MINT operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
};
#pragma endregion