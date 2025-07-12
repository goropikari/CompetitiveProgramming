// https://atcoder.jp/contests/arc174/tasks/arc174_a
// 2025年07月09日 02時22分33秒
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

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, C;
    cin >> N >> C;
    vll A(N);
    rep(i, N) cin >> A[i];

    vll cumsum(N + 1);
    rep(i, N) {
        cumsum[i + 1] = cumsum[i] + A[i];
    }

    ll ans = cumsum[N];

    {
        // max(f(l,r)) = max(f(0,r) - f(0,l))
        //             = max(f(0,r) - min_l (f(0,l)))
        ll t = -INF;
        ll mi = 0;

        rep2(i, 1, N + 1) {
            chmin(mi, cumsum[i - 1]);
            chmax(t, cumsum[i] - mi);
        }

        t *= (C - 1);
        t += cumsum[N];
        chmax(ans, t);
    }

    {
        // min(f(l,r)) = min(f(0,r) - f(0,l))
        //             = min(f(0,r) - max_l (f(0,l)))
        ll t = INF;
        ll mx = -INF;

        rep2(i, 1, N + 1) {
            chmax(mx, cumsum[i - 1]);
            chmin(t, cumsum[i] - mx);
        }

        t *= (C - 1);
        t += cumsum[N];
        chmax(ans, t);
    }
    cout << ans << endl;
}
