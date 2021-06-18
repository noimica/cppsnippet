// 最長部分増加列 O(NlogN)
template <class T>
vec<P> LIS(const vector<T>& A){
    vl dp;
    vec<P> X(A.size());
    REP(i, A.size()){
        auto p = lower_bound(ALL(dp), A[i]);
        if(p != dp.end()){
            *p = A[i];
        }else{
            dp.push_back(A[i]);
        }
        X[i] = {dp.size(), dp[dp.size()-1]};
    }
    return X;
}