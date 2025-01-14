// https://atcoder.jp/contests/math-and-algorithm/tasks/abc075_d
/*2025年01月14日 22時30分43秒*/
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

const ll INF = (ll)9e18 + 9;
// const int INF = (int)2e9 + 7;
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

void solve() {
    ll N, K;
    cin >> N >> K;

    vector<pair<ll, ll>> pts;
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        pts.push_back({x, y});
    }

    vll X(N), Y(N);
    rep(i, N) {
        auto [x, y] = pts[i];
        X[i] = x, Y[i] = y;
    }

    sort(all(X)), sort(all(Y));

    ll ans = INF;
    rep(xi, N) {
        rep2(xj, xi + 1, N) {
            rep(yi, N) {
                rep2(yj, yi + 1, N) {
                    ll xa = X[xi], xb = X[xj], ya = Y[yi], yb = Y[yj];
                    if (xa > xb)
                        swap(xa, xb);
                    if (ya > yb)
                        swap(ya, yb);

                    ll cnt = 0;
                    rep(i, N) {
                        auto [x, y] = pts[i];
                        if (clamp(x, xa, xb) == x && clamp(y, ya, yb) == y)
                            cnt++;
                    }
                    if (cnt >= K)
                        chmin(ans, abs(xa - xb) * abs(ya - yb));
                }
            }
        }
    }
    cout << ans << endl;
}
