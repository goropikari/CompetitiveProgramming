/*https://atcoder.jp/contests/abc396/tasks/abc396_c*/
/*2025年03月08日 21時03分45秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;

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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vll b(n), w(m);
    rep(i, n) cin >> b[i];
    rep(i, m) cin >> w[i];

    sort(rall(b));
    sort(rall(w));

    ll ans = 0;
    ll sumb = 0, sumw = 0, maxw = 0;
    rep(i, n) {
        sumb += b[i];
        if (i < m)
            sumw += w[i];
        chmax(maxw, sumw);
        chmax(ans, sumb + maxw);
    }

    cout << ans << '\n';
}
