// https://atcoder.jp/contests/abc425/tasks/abc425_e
// 2025年09月27日 21時39分58秒
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

    ll T, M;
    cin >> T >> M;

    modint::set_mod(M);
    using mint = modint;

    int upper = 5000;
    vector binom(upper + 1, vector<mint>(upper + 1));
    binom[0][0] = 1;
    rep(i, upper) rep(j, i + 1) {
        binom[i + 1][j] += binom[i][j];
        binom[i + 1][j + 1] += binom[i][j];
    }

    auto cal = [&]() -> void {
        ll N;
        cin >> N;
        vll C(N);
        rep(i, N) cin >> C[i];

        mint ans = 1;
        ll ctot = accumulate(all(C), 0ll);
        ll sub = 0;
        for (auto c : C) {
            ans *= binom[ctot - sub][c];
            sub += c;
        }
        cout << ans.val() << endl;
    };

    while (T--) {
        cal();
    }
}
