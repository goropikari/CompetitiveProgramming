// https://atcoder.jp/contests/abc403/tasks/abc403_d
// Thu 22 Jan 2026 11:30:19 PM JST
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

    ll N, D;
    cin >> N >> D;
    vll A(N);
    rep(i, N) cin >> A[i];

    int m = (ll)2e6 + 5;
    vll freq(m);
    for (ll a : A) freq[a]++;

    if (D == 0) {
        ll ans = N;
        rep(i, m) {
            if (freq[i]) ans--;
        }
        cout << ans << endl;
        return;
    }

    ll ans = 0;
    rep(i, D) {
        vll v;
        for (ll j = i; j < m; j += D) {
            v.push_back(freq[j]);
        }

        // dp[j][k]: j 番目まで見て
        //  k = 0, j 番目のものを残す
        //  k = 1, j 番目のものを捨てる
        // ときの捨てる最小数
        vll dp(2, INF);
        dp[0] = 0;
        dp[1] = freq[i];

        for (ll j = i + D; j < m; j += D) {
            vll dpn(2, INF);
            chmin(dpn[1], min(dp[0], dp[1]) + freq[j]);
            chmin(dpn[0], dp[1]);
            swap(dp, dpn);
        }

        ans += min(dp[0], dp[1]);
    }
    cout << ans << endl;
}
