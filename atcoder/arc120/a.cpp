// https://atcoder.jp/contests/arc120/tasks/arc120_a
// 2025年05月28日 02時48分10秒
#include <bits/stdc++.h>
#include <atcoder/all>
#include <atcoder/segtree.hpp>
using namespace atcoder;
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

    int N;
    cin >> N;
    vll A(N + 1);
    rep(i, N) cin >> A[i + 1];

    vll f(N + 1), amx(N + 1), M(N + 1);
    rep2(i, 1, N + 1) {
        int k = i - 1;
        amx[i] = max(A[i], amx[k]);
        if (A[i] <= amx[k]) {
            M[i] = A[i] + M[k];
            f[i] = f[k] + M[i];
        } else {
            M[i] = A[i] + M[k] + (A[i] - amx[k]);
            f[i] = f[k] + (A[i] - amx[k]) * k + M[i];
        }
        cout << f[i] << endl;
    }
}
