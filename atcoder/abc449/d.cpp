// https://atcoder.jp/contests/abc449/tasks/abc449_d
// Sun 22 Mar 2026 09:07:13 PM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define pb push_back
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

template <typename T>
bool chmin(T& a, T b) {
    bool change = a > b;
    a = min(a, b);
    return change;
}
template <typename T>
bool chmax(T& a, T b) {
    bool change = a < b;
    a = max(a, b);
    return change;
}

template <typename T>
void print(vector<T> v, char delim = ' ') {
    int n = v.size();
    rep(i, n) {
        if (i == 0)
            cout << v[i];
        else
            cout << delim << v[i];
    }
    cout << endl;
}

template <typename T>
void vprint(vector<T> v) {
    for (auto x : v) cout << x << '\n';
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

    ll L, R, D, U;
    cin >> L >> R >> D >> U;

    ll ans = 0;
    rep(_, 2) {
        // |x| > |y| のとき
        rep2(x, L, R + 1) {
            if (x % 2 != 0) continue;
            ll ax = abs(x);
            if (U <= -ax) continue;
            if (ax <= D) continue;
            ll d = max(-ax + 1, D);
            ll u = min(ax - 1, U);
            if (d > u) continue;

            ans += u - d + 1;
        }

        swap(L, D);
        swap(R, U);
    }

    // |x| = |y|
    rep2(i, 1, (ll)1e6 + 5) {
        if (i % 2 != 0) continue;
        for (ll si : {1, -1}) {
            for (ll sj : {1, -1}) {
                ll ti = si * i, tj = sj * i;
                if (clamp(ti, L, R) == ti && clamp(tj, D, U) == tj) ans++;
            }
        }
    }
    if (clamp(0ll, L, R) == 0ll && clamp(0ll, D, U) == 0ll) ans++;

    cout << ans << endl;
}
