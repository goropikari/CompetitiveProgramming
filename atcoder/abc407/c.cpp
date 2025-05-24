// https://atcoder.jp/contests/abc407/tasks/abc407_c
// 2025年05月24日 21時06分04秒
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#include <atcoder/modint>
// using mint = modint998244353;
// using mint = modint1000000007;
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

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    vll A;
    for (char c : S) {
        A.push_back(c - '0');
    }

    ll ans = 0;
    ll cnt = 0;
    reverse(all(A));
    int N = A.size();
    rep(i, N) {
        ll x = (10 + A[i] - cnt) % 10;
        cnt += x;
        cnt %= 10;
        ans += x + 1;
    }
    cout << ans << endl;
}
