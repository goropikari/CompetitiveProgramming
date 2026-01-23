// https://atcoder.jp/contests/abc419/tasks/abc419_e
// Fri 23 Jan 2026 01:06:12 AM JST
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

    ll N, M, L;
    cin >> N >> M >> L;
    vll A(N);
    rep(i, N) {
        cin >> A[i];
        A[i] %= M;
    }

    if (M <= 1) {
        cout << 0 << endl;
        return;
    }

    vvll cost(L, vll(M));
    rep(i, L) {
        rep(m, M) {
            ll sum = 0;
            for (ll j = i; j < N; j += L) {
                if (A[j] <= m)
                    sum += m - A[j];
                else
                    sum += M - A[j] + m;
            }
            cost[i][m] = sum;
        }
    }

    vll dp = cost[0];

    rep2(i, 1, L) {
        vll dpn(M, INF);
        rep(prm, M) {
            rep(m, M) {
                ll nm = (m + prm) % M;
                chmin(dpn[nm], dp[prm] + cost[i][m]);
            }
        }
        swap(dp, dpn);
    }

    cout << dp[0] << endl;
}
