// https://atcoder.jp/contests/abc473/tasks/abc473_e
// Mon 07 Sep 2026 07:40:30 PM JST
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
    for (auto x : v)
        cout << x << '\n';
}

void yesno(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

void Yes() { yesno(true); }

void No() { yesno(false); }

// ceil(a/b)
template <typename T>
T ceil(T a, T b) { return (a + b - 1) / b; }

// floor(a/b)
template <typename T>
T floor(T a, T b) { return a / b; }

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
    vll A(N);
    rep(i, N) cin >> A[i];

    vll cm(N + 1);
    rep(i, N) {
        cm[i + 1] = (cm[i] + A[i]) % K;
    }

    map<ll, vll> mp;
    rep(i, N + 1) {
        mp[cm[i]].pb(i);
    }

    // (start, end]
    using P = pair<ll, ll>;
    vector<P> ps;

    for (auto [k, v] : mp) {
        ll sz = v.size();
        rep(i, sz - 1) {
            ps.pb({v[i], v[i + 1]});
        }
    }

    sort(all(ps), [](P a, P b) -> bool {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    ll now = 0;
    ll ans = 0;

    for (auto [s, e] : ps) {
        if (now <= s) {
            ans++;
            now = e;
        }
    }
    cout << ans << endl;
}
