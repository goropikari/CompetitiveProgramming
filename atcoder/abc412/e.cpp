// https://atcoder.jp/contests/abc412/tasks/abc412_e
// 2025年07月07日 09時21分33秒
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

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll L, R;
    cin >> L >> R;

    // L+1 ~ R にある素冪の個数を数える
    L++;
    ll W = R - L + 1;

    vll x(W), cnt(W);
    rep(i, W) {
        x[i] = L + i;
    }

    int M = 1e7;
    vector<bool> isprime(M, true);
    isprime[0] = isprime[1] = false;
    rep2(i, 2, M) {
        if (!isprime[i]) continue;
        for (int j = i + i; j < M; j += i) {
            isprime[j] = false;
        }

        // (L+i-1)/i * i = (L を超える最小の i の倍数)
        for (ll j = (L + i - 1) / i * i; j <= R; j += i) {
            while (x[j - L] % i == 0) x[j - L] /= i;
            cnt[j - L]++;  // j の値が何個の素数で構成されるかカウント
        }
    }

    ll ans = 1;
    rep(i, W) {
        if (x[i] != 1) cnt[i]++;
        if (cnt[i] == 1) ans++;  // 1種類の素数だけからなる
    }
    cout << ans << endl;
}
