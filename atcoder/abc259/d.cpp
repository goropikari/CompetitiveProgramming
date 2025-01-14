/*https://atcoder.jp/contests/abc259/tasks/abc259_d*/
/*2025年01月10日 22時57分16秒*/
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<ll,ll>;
using P = pair<int, int>;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;
// const ll MOD = (ll)1e9+9;
template <typename T>
void chmin(T& a, T b) {
    a = min(a, b);
}
template <typename T>
void chmax(T& a, T b) {
    a = max(a, b);
}

template <typename T>
void print(vector<T> v) {
    int n = v.size();
    rep(i, n) {
        if (i == 0)
            cout << v[i];
        else
            cout << ' ' << v[i];
    }
    cout << endl;
}

void yesno(bool x) {
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

vll x, y, r;

bool intersect(int i, int j) {
    if (r[i] > r[j])
        swap(i, j);

    ll dx = x[i] - x[j], dy = y[i] - y[j];
    ll dsq = dx * dx + dy * dy;
    ll r1 = r[i], r2 = r[j];
    if (dsq == (r1 + r2) * (r1 + r2))
        return true;
    else if (dsq == (r2 - r1) * (r2 - r1))
        return true;
    else if (dsq < (r2 - r1) * (r2 - r1))
        return false;
    else if (dsq > (r1 + r2) * (r1 + r2))
        return false;

    return true;
}

void solve() {
    int N;
    cin >> N;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    x.resize(N);
    y.resize(N);
    r.resize(N);
    rep(i, N) cin >> x[i] >> y[i] >> r[i];

    int sid = -1, tid = -1;
    rep(i, N) {
        ll dsx = sx - x[i], dsy = sy - y[i];
        ll dssq = dsx * dsx + dsy * dsy;
        if (dssq == r[i] * r[i])
            sid = i;
        ll dtx = tx - x[i], dty = ty - y[i];
        ll dtsq = dtx * dtx + dty * dty;
        if (dtsq == r[i] * r[i])
            tid = i;
    }

    dsu uf(N);
    rep(i, N) {
        rep2(j, i + 1, N) {
            if (intersect(i, j))
                uf.merge(i, j);
        }
    }
    yesno(uf.same(sid, tid));
}
