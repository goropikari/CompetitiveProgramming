// https://atcoder.jp/contests/arc004/tasks/arc004_3
// 2025年07月16日 23時30分14秒
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

// const ll INF = (ll)2e18+9;
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

    ll X, Y;
    char c;
    cin >> X >> c >> Y;

    ll g = gcd(X, Y);
    X /= g;
    Y /= g;

    ll k1 = (4 * X - 2 * Y) / Y / Y;
    ll k2 = (4 * X + 2 * Y) / Y / Y + 1;
    vector<pair<ll, ll>> ans;
    rep2(k, k1, k2 + 1) {
        ll N = k * Y / 2;
        ll M = (N * (N + 1) - k * X) / 2;
        if (N > 0 && M > 0 && M <= N && 2 * N == k * Y && N * (N + 1) - 2 * M == k * X) {
            ans.emplace_back(N, M);
        }
    }
    sort(all(ans));

    if (ans.size()) {
        for (auto [N, M] : ans) cout << N << ' ' << M << endl;
    } else {
        cout << "Impossible" << endl;
    }
}
