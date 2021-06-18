// 遅延セグメント木
#pragma region LazySegmentTree
// https://ei1333.github.io/algorithm/segment-tree.html
// [l, r)
namespace LSTOpt{
    using Monoid = ll;
    using OpMonoid = ll;
    // Command基底クラスの宣言
    struct CmdM{
        virtual Monoid M() = 0;
        virtual Monoid op(Monoid a, Monoid b) = 0;
        virtual OpMonoid p(OpMonoid a, size_t n) = 0;
    };
    struct CmdOp{
        virtual OpMonoid ID() = 0;
        virtual Monoid mapping(Monoid a, OpMonoid b) = 0;
        virtual OpMonoid composition(OpMonoid a, OpMonoid b) = 0;
    };
}
template< typename Monoid = LSTOpt::Monoid, typename OperatorMonoid = LSTOpt::OpMonoid >
struct LST {
    int sz;
    vector< Monoid > data;
    vector< OperatorMonoid > lazy;
    LSTOpt::CmdM* m;
    LSTOpt::CmdOp* op;
    LST(int n, LSTOpt::CmdM* cmdm, LSTOpt::CmdOp* cmdop)
        //: f(cmdm.op), g(cmdop.mapping), h(cmdop.composition), p(cmdm.p), M1(cmdm.M()), OM0(cmdop.ID())
        {
            this->m = cmdm;
            this->op = cmdop;
            sz = 1;
            while(sz < n) sz <<= 1;
            data.assign(2 * sz, m->M());
            lazy.assign(2 * sz, op->ID());
        }

    void set(int k, const Monoid &x) {
        data[k + sz] = x;
    }
    void build(){
        for(int k = sz - 1; k > 0; k--) {
            data[k] = m->op(data[2 * k + 0], data[2 * k + 1]);
        }
    }
    void propagate(int k, int len) {
        if(lazy[k] != op->ID()) {
            if(k < sz) {
                lazy[2 * k + 0] = op->composition(lazy[2 * k + 0], lazy[k]);
                lazy[2 * k + 1] = op->composition(lazy[2 * k + 1], lazy[k]);
            }
            data[k] = op->mapping(data[k], m->p(lazy[k], len));
            lazy[k] = op->ID();
        }
    }
    Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r) {
        propagate(k, r - l);
        if(r <= a || b <= l) {
            return data[k];
        }else if(a <= l && r <= b) {
            lazy[k] = op->composition(lazy[k], x);
            propagate(k, r - l);
            return data[k];
        }else{
            return data[k] = m->op(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
                                update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
        }
    }
    Monoid update(int a, int b, const OperatorMonoid &x) {
        return update(a, b, x, 1, 0, sz);
    }
    Monoid query(int a, int b, int k, int l, int r){
        propagate(k, r - l);
        if(r <= a || b <= l) {
            return m->M();
        }else if(a <= l && r <= b) {
            return data[k];
        }else{
            return m->op(query(a, b, 2 * k + 0, l, (l + r) >> 1),
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
namespace LSTOpt{
    struct secadd : CmdOp{
        // 単位元
        Monoid ID(){ return 0; }
        // 要素と作用素のマージ
        Monoid mapping(Monoid a, OpMonoid b) { return a + b; };
        // 作用素と作用素のマージ
        OpMonoid composition(OpMonoid a, OpMonoid b) { return a + b; };
    } ;
    struct seccng : CmdOp{
        // 単位元 ※要変更
        Monoid ID(){ return INF; }
        // 要素と作用素のマージ
        Monoid mapping(Monoid a, OpMonoid b) { return (b==ID())?a:b; };
        // 作用素と作用素のマージ
        OpMonoid composition(OpMonoid a, OpMonoid b) { return (b==ID())?a:b; };
    };
    // min
    struct secmin : CmdM{
        // 単位元
        Monoid M(){ return INF; }
        // 演算
        Monoid op(Monoid a, Monoid b){ return std::min(a, b); }
        // 作用素マージの前にかませる関数
        OpMonoid p(OpMonoid a, size_t n){ return a; }
    };
    // sum
    struct secsum : CmdM{
        // 単位元
        Monoid M(){ return 0; }
        // 演算
        Monoid op(Monoid a, Monoid b){ return a+b; }
        // 作用素マージの前にかませる関数
        OpMonoid p(OpMonoid a, size_t n){ return a*n; }
    };
};
#pragma endregion