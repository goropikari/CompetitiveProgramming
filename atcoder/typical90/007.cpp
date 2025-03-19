/*https://atcoder.jp/contests/typical90/tasks/typical90_g*/
/*2025年03月19日 02時31分21秒*/
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    int q;
    cin >> q;
    vll b(q);
    rep(i, q) cin >> b[i];

    sort(all(a));

    ll ans = 0;
    for (ll x : b) {
        auto it = lower_bound(all(a), x);
        ll t = INF;
        if (it != a.begin()) {
            chmin(t, abs(x - *prev(it)));
        }
        if (it != a.end()) {
            chmin(t, abs(x - *it));
        }
        cout << t << endl;
    }
}
