// https://atcoder.jp/contests/arc149/tasks/arc149_a
// 2025年05月29日 22時26分52秒
#include <bits/stdc++.h>
#include <atcoder/all>
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

    ll N, M;
    cin >> N >> M;

    modint::set_mod(M);
    using mint = modint;

    auto chmin_string = [](string& a, string& b) -> void {
        if (a.size() > b.size()) return;
        if (a.size() < b.size()) {
            a = b;
            return;
        }
        if (a < b) a = b;
    };

    string ans = "";
    rep2(i, 1, 10) {
        string s = "";
        mint x = 0;
        rep(j, N) {
            x *= 10;
            x += i;
            s.push_back('0' + i);
            if (x == 0) chmin_string(ans, s);
        }
    }

    if (ans == "") ans = "-1";
    cout << ans << endl;
}
