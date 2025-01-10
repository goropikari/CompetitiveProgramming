/*https://atcoder.jp/contests/abc214/tasks/abc214_d*/
/*2025年01月08日 22時36分14秒*/
/* give up 2025年01月08日 23時37分30秒*/
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

void solve() {
    int N;
    cin >> N;
    vll u(N - 1), v(N - 1), w(N - 1);
    rep(i, N - 1) cin >> u[i] >> v[i] >> w[i];

    vector<tuple<ll, ll, ll>> edges;
    rep(i, N - 1) {
        edges.push_back({w[i], u[i] - 1, v[i] - 1});
    }

    dsu uf(N);

    ll ans = 0;
    sort(all(edges));
    for (auto [w, u, v] : edges) {
        ans += w * uf.size(u) * uf.size(v);
        uf.merge(u, v);
    }
    cout << ans << endl;
}
