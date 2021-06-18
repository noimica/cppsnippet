#pragma region LazySegmentTree
// https://ei1333.github.io/algorithm/segment-tree.html
template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {
    using F = function< Monoid(Monoid, Monoid) >;
    using G = function< Monoid(Monoid, OperatorMonoid) >;
    using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;
    using P = function< OperatorMonoid(OperatorMonoid, int) >;
    int sz;
    vector< Monoid > data;
    vector< OperatorMonoid > lazy;
    const F f;
    const G g;
    const H h;
    const P p;
    const Monoid M1;
    const OperatorMonoid OM0;
    LazySegmentTree(int n, const F op, const G mapping, const H composition, const P p,
                    const Monoid &M, const OperatorMonoid ID)
        : f(op), g(mapping), h(composition), p(p), M1(M), OM0(ID)
        {
            sz = 1;
            while(sz < n) sz <<= 1;
            data.assign(2 * sz, M1);
            lazy.assign(2 * sz, OM0);
        }

    void set(int k, const Monoid &x) {
        data[k + sz] = x;
    }
    void build(){
        for(int k = sz - 1; k > 0; k--) {
            data[k] = f(data[2 * k + 0], data[2 * k + 1]);
        }
    }
    void propagate(int k, int len) {
        if(lazy[k] != OM0) {
            if(k < sz) {
                lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
                lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
            }
            data[k] = g(data[k], p(lazy[k], len));
            lazy[k] = OM0;
        }
    }
    Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r) {
        propagate(k, r - l);
        if(r <= a || b <= l) {
            return data[k];
        }else if(a <= l && r <= b) {
            lazy[k] = h(lazy[k], x);
            propagate(k, r - l);
            return data[k];
        }else{
            return data[k] = f(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
                                update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
        }
    }
    Monoid update(int a, int b, const OperatorMonoid &x) {
        return update(a, b, x, 1, 0, sz);
    }
    Monoid query(int a, int b, int k, int l, int r){
        propagate(k, r - l);
        if(r <= a || b <= l) {
            return M1;
        }else if(a <= l && r <= b) {
            return data[k];
        }else{
            return f(query(a, b, 2 * k + 0, l, (l + r) >> 1),
                    query(a, b, 2 * k + 1, (l + r) >> 1, r));
        }
    }
    Monoid query(int a, int b) {
        return query(a, b, 1, 0, sz);
    }
    Monoid operator[](const int &k) {
        return query(k, k + 1);
    }
};
namespace lazysegtreeOpt{
    using Monoid = ll;
    using OpMonoid = ll;
    namespace secadd{
        // 要素と作用素のマージ
        Monoid mapping(Monoid a, OpMonoid b) { return a + b; };
        // 作用素と作用素のマージ
        OpMonoid composition(OpMonoid a, OpMonoid b) { return a + b; };
    };
    namespace seccng{
        OpMonoid ID = INF;    //単位元 ※要変更
        // 要素と作用素のマージ
        Monoid mapping(Monoid a, OpMonoid b) { return (b==ID)?a:b; };
        // 作用素と作用素のマージ
        OpMonoid composition(OpMonoid a, OpMonoid b) { return (b==ID)?a:b; };
    }
    namespace secmin{
        const Monoid M = INF;    //単位元
        // 演算
        Monoid op(Monoid a, Monoid b){ return std::min(a, b); }
        // 作用素マージの前にかませる関数
        OpMonoid p(OpMonoid a, size_t n){ return a; }
    };
    namespace secsum{
        const Monoid M = 0;    //単位元
        // 演算
        Monoid op(Monoid a, Monoid b){ return a+b; }
        // 作用素マージの前にかませる関数
        OpMonoid p(OpMonoid a, size_t n){ return a*n; }
    };
};
#pragma endregion