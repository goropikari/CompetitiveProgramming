// https://atcoder.jp/contests/tdpc/tasks/tdpc_game
// 2025年07月21日 17時37分57秒
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

    ll N, M;
    cin >> N >> M;
    vll A(N + 1), B(M + 1);
    rep(i, N) cin >> A[i + 1];
    rep(i, M) cin >> B[i + 1];

    ll sum = accumulate(all(A), 0ll) + accumulate(all(B), 0ll);

    vvll memo(N + 1, vll(M + 1));

    auto f = [&](auto f, ll rem, int a = 0, int b = 0) -> ll {
        if (memo[a][b]) return memo[a][b];
        if (a == N && b == M) return 0;

        ll l = INF, r = INF;
        if (a + 1 <= N)
            l = f(f, rem - A[a + 1], a + 1, b);
        if (b + 1 <= M)
            r = f(f, rem - B[b + 1], a, b + 1);

        return memo[a][b] = rem - min(l, r);
    };

    cout << f(f, sum) << endl;
}
