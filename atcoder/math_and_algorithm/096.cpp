// https://atcoder.jp/contests/math-and-algorithm/tasks/abc204_d
/*2025年01月16日 22時28分43秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <numeric>
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
    ll N;
    cin >> N;
    vll T(N);
    rep(i, N) cin >> T[i];

    ll tot = accumulate(all(T), 0);

    vector<bool> par(tot + 1, 0);
    par[0] = 1;

    rep(i, N) {
        for (ll j = tot; j - T[i] >= 0; j--) {
            if (par[j - T[i]])
                par[j] = 1;
        }
    }

    ll ans = tot;
    rep(i, tot + 1) {
        if (par[i])
            chmin(ans, max(1LL * i, tot - i));
    }
    cout << ans << endl;
}
