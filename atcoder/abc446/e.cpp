// https://atcoder.jp/contests/abc446/tasks/abc446_e
// Sat 21 Feb 2026 09:30:37 PM JST
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
void chmin(T& a, T b) { a = min(a, b); }
template <typename T>
void chmax(T& a, T b) { a = max(a, b); }

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

void yesno(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

void Yes() { yesno(true); }

void No() { yesno(false); }

// ceil(a/b)
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

// floor(a/b)
ll floor(ll a, ll b) { return a / b; }

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll M, A, B;
    cin >> M >> A >> B;
    A %= M;
    B %= M;

    vvint ok(M, vint(M)), visited(M, vint(M));

    // dfs(s1, s2): s1, s2 から始めて M の倍数になるかどうか判定
    // true  -> M の倍数になる
    // false -> M の倍数にならない
    auto dfs = [&](auto dfs, ll s1, ll s2) -> bool {
        if (s1 == 0 || s2 == 0 || ok[s1][s2]) return true;

        if (visited[s1][s2]) {
            return false;
        }

        visited[s1][s2] = 1;
        ll s3 = (A * s2 + B * s1) % M;
        return ok[s1][s2] = dfs(dfs, s2, s3);
    };

    ll ans = 0;
    rep(x, M) rep(y, M) {
        if (!dfs(dfs, x, y))
            ans++;
    }

    cout << ans << endl;
}
