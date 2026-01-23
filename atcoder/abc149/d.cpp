// https://atcoder.jp/contests/abc149/tasks/abc149_d
// Thu 22 Jan 2026 09:37:12 PM JST
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

// const ll INF = (ll)2e18+9;
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

    ll N, K;
    cin >> N >> K;
    ll R, S, P;
    cin >> R >> S >> P;
    string T;
    cin >> T;

    vll v;
    rep(i, N) {
        ll x = 0;
        if (T[i] == 'r') x = 0;
        if (T[i] == 's') x = 1;
        if (T[i] == 'p') x = 2;
        v.push_back(x);
    }

    vll hand = {2, 0, 1};
    vll pt = {R, S, P};

    ll ans = 0;
    rep(s, K) {
        int i = s;
        int pr = -1;
        for (int j = i; j < N; j += K) {
            ll win = hand[v[j]];
            if (win == pr) {
                pr = -1;
            } else {
                ans += pt[win];
                pr = win;
            }
        }
    }
    cout << ans << endl;
}
