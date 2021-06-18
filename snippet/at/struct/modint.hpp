// mod Pのための型
#pragma region modint
template<ll m> struct modint{
protected:
    ll v=0;
public:
    //コンストラクタ
    modint(ll x=0){while(x<0)x+=m;v=x%m;}
    modint(const modint &r){v=r.val();}
    //算術演算子(単項)
    modint operator -(){return modint(-v);} 
    modint& operator ++(){if(++v>=m)v-=m; return *this;}
    modint operator ++(int){modint t = *this; ++*this; return t;}
    modint& operator --(){if(--v<0)v+=m; return *this;}
    modint operator --(int){modint t = *this; --*this; return t;}
    //算術演算子(二項)
    friend modint operator +(const modint &l, const modint &r){return modint(l)+=r;}
    friend modint operator -(const modint &l, const modint &r){return modint(l)-=r;}
    friend modint operator *(const modint &l, const modint &r){return modint(l)*=r;}
    friend modint operator /(const modint &l, const modint &r){return modint(l)/=r;}
    // キャスト演算子
    explicit operator int() const {return val();}
    explicit operator ll() const {return val();}
    //代入演算子
    modint &operator +=(const modint &r){
        v+=r.val();
        if(v>=m)v-=m;
        return *this;
    }
    modint &operator -=(const modint &r){
        if(v<r.val())v+=m;
        v-=r.val();
        return *this;
    }
    modint &operator *=(const modint &r){
        v=v*r.val()%m;
        return *this;
    }
    modint &operator /=(const modint &r){
        v=v*r.inv().val()%m;
        return *this;
    }
    //等価比較演算子
    friend bool operator ==(const modint &l, const modint& r){return l.val()==r.val();}
    friend bool operator <(const modint &l, const modint& r){return l.val()<r.val();}
    friend bool operator >(const modint &l, const modint& r){return l.val()>r.val();}
    friend bool operator !=(const modint &l, const modint& r){return l.val()!=r.val();}
    // 各種関数
    int val() const{return v;}
    constexpr static ll mod(){return m;}
    static modint raw(ll x){modint r;r.v=x;return r;}
    modint inv() const{
        ll a=v,b=m,u=1,v=0;
        while(b){
            ll t=a/b;
            a-=t*b;swap(a,b);
            u-=t*v;swap(u,v);
        }
        u %= m; 
        if (u < 0) u += m;
        return u;
    }
    modint pow(ll n) const{
        modint ret = 1, x(v);
        while (n > 0) {
            if (n & 1) ret *= x;
            x *= x;
            n >>= 1;
        }
        return ret;
    }
    //入出力ストリーム
    friend istream &operator>>(istream &is,modint& x){ll t;is>>t;x=t;return (is);}
    friend ostream &operator<<(ostream &os,const modint& x){return os<<x.val();}
    
};
using modint1000000007 = modint<1000000007>;
using modint998244353 = modint<998244353>;
#pragma endregion