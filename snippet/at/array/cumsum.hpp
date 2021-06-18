//Aの累積和をとる．[l, r)の和はR[r] - R[l]で取ることができる．
template<class T>
vec<T> cumsum(const vec<T> &A) {
    vec<T> R(A.size()+1);
    REP(i, A.size()) R[i + 1] = R[i] + A[i];
    return R;
}