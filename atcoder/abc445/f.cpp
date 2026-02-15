// https://atcoder.jp/contests/abc445/tasks/abc445_f
// Sun 15 Feb 2026 04:38:35 PM JST
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

struct Cost {
    ll N;
    vvll data;

    Cost(ll N) : N(N) {
        data = vvll(N, vll(N, INF));
        rep(i, N) data[i][i] = 0;
    }

    Cost operator*(const Cost& other) {
        vvll vals(N, vll(N, INF));

        rep(k, N) rep(i, N) rep(j, N) {
            chmin(vals[i][j], this->data[i][k] + other.data[k][j]);
        }

        Cost ret(N);
        ret.data = vals;
        return ret;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, K;
    cin >> N >> K;
    vvll C(N, vll(N));
    rep(i, N) rep(j, N) cin >> C[i][j];

    ll M = 31;

    // powcost[d][i][j]: j から出発して 2^d の操作後に i に到達するときの最小コスト
    vector powcost(M, Cost(N));
    powcost[0].data = C;
    rep2(d, 1, M) {
        powcost[d] = powcost[d - 1] * powcost[d - 1];
    }

    Cost now(N);
    rep(i, M) {
        if (K >> i & 1) {
            now = powcost[i] * now;
        }
    }

    vll ans;
    rep(i, N) {
        cout << now.data[i][i] << '\n';
    }
}
