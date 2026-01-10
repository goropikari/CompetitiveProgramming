// https://atcoder.jp/contests/abc362/tasks/abc362_e
// 2025年07月22日 23時49分21秒
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

    vll diffs;
    rep(i, N) rep2(j, i + 1, N) diffs.push_back(A[j] - A[i]);
    sort(all(diffs));
    diffs.erase(unique(all(diffs)), diffs.end());

    ll dsz = diffs.size();

    // dp[i][L][d]: i 番目の数字から初めて長さ L、公差 d の数列の場合の数
    vector dp(N, vector(N + 1, vector<mint>(dsz)));

    rep(i, N) {
        rep(di, dsz) {
            dp[i][1][di] = 1;
        }
    }

    rep2(L, 2, N + 1) {
        rep(i, N) {
            rep2(j, i + 1, N) {
                auto di = lower_bound(all(diffs), A[j] - A[i]) - diffs.begin();
                dp[i][L][di] += dp[j][L - 1][di];
            }
        }
    }

    vector<mint> ans = {N};
    rep2(L, 2, N + 1) {
        mint tmp = 0;
        rep(i, N) rep(di, dsz) {
            tmp += dp[i][L][di];
        }
        ans.push_back(tmp);
    }

    rep(i, N) {
        if (i == 0)
            cout << ans[i].val();
        else
            cout << ' ' << ans[i].val();
    }
    cout << endl;
}
