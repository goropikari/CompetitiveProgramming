// https://atcoder.jp/contests/past202212-open/tasks/past202212_f
// 2025年06月23日 18時07分23秒
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

    ll N, A, B, C, D, x1, x2;
    char c;
    cin >> N >> A >> B >> C >> D >> x1 >> c >> x2;
    ll X = x1 * 1000 + x2;

    auto f = [&](ll x) -> bool {
        // (A+x + 2*B + 3*C + 4*D) * 1000 <= (N+x)*X
        // (A + 2*B + 3*C + 4*D) * 1000 - NX <= x(X - 1000)
        // ((A + 2*B + 3*C + 4*D) * 1000 - NX) / (X-1000) <= x
        ll d = X - 1000;
        return (((A + 2 * B + 3 * C + 4 * D) * 1000 - N * X) + d - 1) / d <= x;
    };

    ll ac = INF, wa = -1;
    while (ac - wa > 1) {
        ll wj = (ac + wa) / 2;
        if (f(wj)) {
            ac = wj;
        } else {
            wa = wj;
        }
    }
    cout << ac << endl;
}
