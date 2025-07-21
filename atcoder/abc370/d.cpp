// https://atcoder.jp/contests/abc370/tasks/abc370_d
// 2025年07月21日 14時35分33秒
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

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
    cout << (x ? "Yes" : "No") << '\n';
}

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

// ceil(a/b)
ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

// floor(a/b)
ll floor(ll a, ll b) {
    return a / b;
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll H, W, Q;
    cin >> H >> W >> Q;
    vector<set<ll>> rows(H), cols(W);

    rep(r, H) rep(c, W) {
        rows[r].insert(c);
        cols[c].insert(r);
    }

    rep(i, Q) {
        int r, c;
        cin >> r >> c;
        r--, c--;

        if (rows[r].count(c)) {  // 壁あり
            rows[r].erase(c);
            cols[c].erase(r);
        } else {  // 壁なし
            {     // 右
                auto it = rows[r].lower_bound(c);
                if (it != rows[r].end()) {
                    int cid = *it;
                    rows[r].erase(it);
                    cols[cid].erase(r);
                }
            }
            {  // 左
                auto it = rows[r].lower_bound(c);
                if (it != rows[r].begin()) {
                    it = prev(it);
                    int cid = *it;
                    rows[r].erase(it);
                    cols[cid].erase(r);
                }
            }
            {  // 上
                auto it = cols[c].lower_bound(r);
                if (it != cols[c].begin()) {
                    it = prev(it);
                    int rid = *it;
                    rows[rid].erase(c);
                    cols[c].erase(it);
                }
            }
            {  // 下
                auto it = cols[c].lower_bound(r);
                if (it != cols[c].end()) {
                    int rid = *it;
                    rows[rid].erase(c);
                    cols[c].erase(it);
                }
            }
        }
    }

    ll ans = 0;
    rep(i, H) ans += (ll)rows[i].size();
    cout << ans << endl;
}
