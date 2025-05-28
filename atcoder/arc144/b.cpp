// https://atcoder.jp/contests/arc144/tasks/arc144_b
// 2025年05月29日 01時59分41秒
#include <bits/stdc++.h>
#include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
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
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18 + 9;
const int INF = (int)2e9 + 7;

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

    ll N, a, b;
    cin >> N >> a >> b;
    vll A(N);
    rep(i, N) cin >> A[i];

    auto check = [&](ll x) -> bool {
        ll l = 0, r = 0;
        rep(i, N) {
            if (A[i] < x) {
                l += (x - A[i] + a - 1) / a;
            } else {
                r += (A[i] - x) / b;
            }
        }

        return l <= r;
    };

    ll ac = 0, wa = *max_element(all(A)) + 1;
    while (wa - ac > 1) {
        ll wj = (wa + ac) / 2;
        if (check(wj)) {
            ac = wj;
        } else {
            wa = wj;
        }
    }

    cout << ac << endl;
}
