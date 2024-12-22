/*https://atcoder.jp/contests/abc264/tasks/abc264_c*/
// #include <atcoder/all>
// using namespace atcoder;
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

void solve() {
    int ha, wa;
    cin >> ha >> wa;
    vvint mata(ha, vint(wa));
    rep(i, ha) rep(j, wa) cin >> mata[i][j];

    int hb, wb;
    cin >> hb >> wb;
    vvint matb(hb, vint(wb));
    rep(i, hb) rep(j, wb) cin >> matb[i][j];

    bool ok = false;
    rep(i, 1 << ha) {
        rep(j, 1 << wa) {
            if (__builtin_popcount(i) != hb || __builtin_popcount(j) != wb)
                continue;

            vint hidx, widx;
            rep(k, ha) {
                if ((i >> k) & 1)
                    hidx.push_back(k);
            }
            rep(k, wa) {
                if ((j >> k) & 1)
                    widx.push_back(k);
            }

            bool tmp = true;
            rep(k, hb) {
                rep(l, wb) {
                    if (mata[hidx[k]][widx[l]] != matb[k][l])
                        tmp = false;
                }
            }
            ok = ok || tmp;
        }
    }

    yesno(ok);
}

int main() {
    solve();
    return 0;
}
