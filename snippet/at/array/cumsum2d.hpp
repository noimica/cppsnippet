// [x1, x2) x [y1, y2) は
// s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1]
// で求まる
vec<vl> cumsum2d(const vec<vl>& a){
    ll H = a.size(), W = a[0].size();
    vec<vl> s(H+1, vl(W+1));
    REP(i, H){
        REP(j, W){
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];
        }
    }
    return s;
}