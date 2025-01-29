/*https://atcoder.jp/contests/abc371/tasks/abc371_d*/
/*2025年01月27日 02時05分38秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
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
    vll X(N), P(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> P[i];

    vll cumsum(N + 1);
    rep(i, N) cumsum[i + 1] = cumsum[i] + P[i];

    int q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;

        auto lit = lower_bound(all(X), l);
        auto rit = upper_bound(all(X), r);
        int lidx = lit - X.begin(), ridx = rit - X.begin();

        cout << cumsum[ridx] - cumsum[lidx] << endl;
    }
}
