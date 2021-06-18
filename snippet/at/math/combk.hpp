#pragma region combk
// nCrを求める
// 前処理 O(k)
// クエリ O(k)
template <class MINT>
struct comb {
    vector<MINT> fact, ifact;
    comb(int k):fact(k+1),ifact(k+1) {
        fact[0] = 1;
        for (int i = 1; i <= k; ++i) fact[i] = fact[i-1]*i;
        ifact[k] = fact[k].inv();
        for (int i = k; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    MINT operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        MINT ans(1);
        for(int i = n; i >= n - k + 1; --i) ans *= i;
        return ans * ifact[k];
    }
};
#pragma endregion