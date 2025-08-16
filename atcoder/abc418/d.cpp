// https://atcoder.jp/contests/abc418/tasks/abc418_d
// 2025年08月09日 21時16分39秒
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

// ceil(a/b)
ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

// floor(a/b)
ll floor(ll a, ll b) {
    return a / b;
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    string T;
    cin >> N >> T;

    fenwick_tree<ll> fw(N);
    int pr = T[0] == '1';
    fw.add(0, pr);
    rep2(i, 1, N) {
        if (pr == 1 && T[i] == '1') {
            fw.add(i, 1);
            pr = 1;
        } else if (pr == 1 && T[i] == '0') {
            fw.add(i, 0);
            pr = 0;
        } else if (pr == 0 && T[i] == '1') {
            fw.add(i, 0);
            pr = 0;
        } else if (pr == 0 && T[i] == '0') {
            fw.add(i, 1);
            pr = 1;
        }
    }

    // rep(i, N) cout << fw.sum(i, i + 1) << endl;

    ll ans = 0;
    rep(i, N) {
        int x = T[i] - '0';
        ll numok = fw.sum(i, N);
        if (x == 0) {
            if (fw.sum(i, i + 1) == 1) {
                ll tot = N - i;
                ans += tot - numok;
            } else {
                ans += numok;
            }
        } else {  // x== 1
            if (fw.sum(i, i + 1) == 1) {
                ans += numok;
            } else {
                ll tot = N - i;
                ans += tot - numok;
            }
        }
    }
    cout << ans << endl;
}
