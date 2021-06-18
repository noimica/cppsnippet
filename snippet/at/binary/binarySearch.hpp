// x∈[l, r] | f(x) = true となる最大のxを返す
template <class Func>
ll BinarySearch(ll l, ll r, Func f){
    while(l < r){
        const ll m = (l+r+1)/2;
        if(f(m)) l = m;
        else     r = m-1;
    }
    return l;
}