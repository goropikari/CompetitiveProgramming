// https://atcoder.jp/contests/joi2016ho/tasks/joi2016ho_b
// Sun 01 Mar 2026 08:52:37 PM JST
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

    ll N;
    cin >> N;
    string S;
    cin >> S;

    vint J, O, I;
    rep(i, N) {
        if (S[i] == 'J') J.pb(i);
        if (S[i] == 'O') O.pb(i);
        if (S[i] == 'I') I.pb(i);
    }

    vector<pair<ll, ll>> ps;
    for (int x : O) {
        auto lit = lower_bound(all(J), x);
        auto rit = lower_bound(all(I), x);
        ll l = lit - J.begin(), r = I.end() - rit;
        ps.emplace_back(l, r);
    }

    ll ans = 0;

    // 先頭に J を追加
    {
        ll sum = 0;
        for (auto [l, r] : ps) sum += (l + 1) * r;
        chmax(ans, sum);
    }

    // 末尾に I を追加
    {
        ll sum = 0;
        for (auto [l, r] : ps) sum += l * (r + 1);
        chmax(ans, sum);
    }

    ll base = 0;
    {
        for (auto [l, r] : ps) base += l * r;
    }
    rep(i, N) {
        auto l = lower_bound(all(J), i) - J.begin();
        auto r = I.end() - lower_bound(all(I), i);
        chmax(ans, base + l * r);
    }

    cout << ans << endl;
}
