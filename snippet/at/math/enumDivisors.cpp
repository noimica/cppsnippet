// 約数列挙
//O(√N)
vector<ll> enumDivisors(ll N) {
    vector<ll> res1, res2;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res1.push_back(i);
            if (N/i != i) res2.push_back(N/i);
        }
    }
    res1.reserve(res1.size()+res2.size());
    copy(res2.rbegin(), res2.rend(), back_inserter(res1));
    return res1;
}