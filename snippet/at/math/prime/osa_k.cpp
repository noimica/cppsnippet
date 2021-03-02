#pragma region osa_k
// 素因数分解に前処理をかける
// 前処理 O(NloglogN)
// クエリ O(logN)
struct osa_k{
    vec<ll> min_factor;
    osa_k(int N): min_factor(N+1){
        //2以上の数を一度素数候補に入れる
        for(int i = 0; i <= N; i++) min_factor[i] = i;
        //それぞれの数について最小の素因数を求める
        for(int i = 2; i*i <= N; i++){
            if(min_factor[i] == i){
                for(int j = 2; i*j <= N; j++){
                    if(min_factor[i*j] > i){
                        min_factor[i*j] = i;
                    }
                }
            }
        }
    }
    vec<P> factorize(int N){
        vec<P> res;
        vec<P>::iterator it;
        int b = -1;
        while(N > 1){
            if(b != min_factor[N]){
                res.push_back({min_factor[N], 0});
                b = min_factor[N];
                it = res.end()-1;
            }
            it->se++;
            N /= min_factor[N];
        }
        return move(res);
    }
};
#pragma endregion