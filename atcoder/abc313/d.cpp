// https://atcoder.jp/contests/abc313/tasks/abc313_d
// Thu 12 Feb 2026 09:49:42 PM JST
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

    ll N, K;
    cin >> N >> K;

    vvint qs(N, vint(N));
    rep(i, K + 1) rep(j, K + 1) {
        qs[i][j] = 1;
        if (i == j) qs[i][j] = 0;
    }

    rep2(i, K + 1, N) rep(j, K - 1) {
        qs[i][j] = 1;
    }
    rep2(i, K + 1, N) qs[i][i] = 1;

    vll ret(N);
    rep(i, N) {
        cout << "?";
        rep(j, N) {
            if (qs[i][j]) cout << ' ' << j + 1;
        }
        cout << endl;
        cout << flush;

        ll t;
        cin >> t;
        ret[i] = t;
    }

    int parity = 0;
    rep(i, K + 1) parity ^= ret[i];

    vll ans(N);
    rep(i, K + 1) {
        ans[i] = parity ^ ret[i];
    }

    int head = 0;
    rep(i, K - 1) {
        head ^= ans[i];
    }

    rep2(i, K + 1, N) {
        ans[i] = head ^ ret[i];
    }

    cout << "! ";
    print(ans);
}
