// https://atcoder.jp/contests/abc117/tasks/abc117_d
// 2025年06月10日 18時32分56秒
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

    ll N, K;
    cin >> N >> K;
    vll A(N);
    rep(i, N) cin >> A[i];

    vint Kbit;
    vvint Abit(N);
    int mx = 60;

    {
        ll t = K;
        rep(i, mx) {
            Kbit.push_back(t % 2);
            t /= 2;
        }
        reverse(all(Kbit));

        rep(i, N) {
            ll a = A[i];
            rep(j, mx) {
                Abit[i].push_back(a % 2);
                a /= 2;
            }
            reverse(all(Abit[i]));
        }
    }

    vector dp(mx + 1, vll(2));
    rep2(i, 1, mx + 1) {
        int t = Kbit[i - 1];
        ll cnt = 0;
        rep(j, N) {
            cnt += Abit[j][i - 1];
        }

        rep(d, 2) {
            if (d < t) {
                chmax(dp[i][1], dp[i - 1][0] * 2 + cnt);
            }
            if (d == t) {
                if (d == 0)
                    chmax(dp[i][0], dp[i - 1][0] * 2 + cnt);
                else
                    chmax(dp[i][0], dp[i - 1][0] * 2 + N - cnt);
            }
            if (dp[i - 1][1]) {
                chmax(dp[i][1], dp[i - 1][1] * 2 + max(N - cnt, cnt));
            }
        }
    }

    cout << max(dp[mx][0], dp[mx][1]) << endl;
}
