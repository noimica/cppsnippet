#pragma region fact
template <class T>
T fact(T x){
    T ret=1;
    ll i_len=(ll)x;
    for(T i=2; (ll)i<=i_len; i+=1){
        ret*=i;
    }
    return ret;
}
#pragma endregion