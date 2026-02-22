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

    vvint ng(M, vint(M));
    vvint visited(M, vint(M));

    auto dfs = [&](auto dfs, ll s1, ll s2) -> bool {
        // 結果が確定している
        if (s1 == 0 || s2 == 0) return false;
        if (ng[s1][s2]) return false;

        // 結果が確定していない状態で訪れたことがある状態に帰って来たとき
        // 道中 0 にならない繰り返しになるので以降 M の倍数は出ない
        if (visited[s1][s2]) {
            return true;
        }

        visited[s1][s2] = 1;
        ll s3 = (A * s2 + B * s1) % M;
        if (dfs(dfs, s2, s3)) {
            return true;
        }
        ng[s1][s2] = 1;
        return false;
    };

    ll ans = 0;
    rep(x, M) rep(y, M) {
        if (dfs(dfs, x, y))
            ans++;
    }

    cout << ans << endl;
}
