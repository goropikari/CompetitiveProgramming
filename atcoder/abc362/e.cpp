// https://atcoder.jp/contests/abc362/tasks/abc362_e
// 2025年06月19日 01時24分16秒
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
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
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
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

    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    vector<mint> ans(N);
    ans[0] = N;
    ans[1] = (mint)N * (N - 1) / 2;

    // dp[d][l][r]
    map<ll, vector<vector<mint>>> dp;
    map<ll, vvint> used;
    rep(l, N) rep2(r, l + 1, N) {
        ll d = A[r] - A[l];
        if (!dp.count(d)) {
            dp[d] = vector(N, vector<mint>(N));
        }
        if (!used.count(d)) {
            used[d] = vector(N, vint(N));
        }
        used[d][l][r] = 1;
        dp[d][l][r]++;
    }

    rep2(i, 2, N) {
        map<ll, vector<vector<mint>>> dpn;
        map<ll, vvint> usedn;
        for (auto [d, v] : dp) {
            if (!dpn.count(d))
                dpn[d] = vector(N, vector<mint>(N));
            if (!usedn.count(d))
                usedn[d] = vector(N, vint(N));
            rep(l, N) rep2(m, l + 1, N) rep2(r, m + 1, N) {
                if (used[d][l][m] && used[d][m][r]) {
                    dpn[d][l][r] += v[l][m] * v[m][r];
                    usedn[d][l][r] = 1;
                }
            }
        }

        swap(dp, dpn);
        swap(used, usedn);

        mint tot = 0;
        for (auto [d, v] : dp) {
            rep(l, N) rep2(r, l + 1, N) {
                tot += v[l][r];
            }
        }
        ans[i] = tot;
    }

    rep(i, N) {
        if (i != 0) cout << ' ';
        cout << ans[i].val();
    }
    cout << endl;
}
