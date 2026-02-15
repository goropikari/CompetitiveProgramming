// https://atcoder.jp/contests/abc313/tasks/abc313_d
// Thu 12 Feb 2026 09:49:42 PM JST
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

    vint group0, group1;
    vint q;
    rep(i, K - 1) q.push_back(i);

    rep2(i, K - 1, N) {
        q.push_back(i);
        cout << "?";
        for (ll x : q) cout << " " << x + 1;
        cout << '\n';
        cout << flush;
        q.pop_back();

        int T;
        cin >> T;
        if (T == -1) return;
        if (T == 0)
            group0.push_back(i);
        else
            group1.push_back(i);
    }

    vint q2;
    {
        vint tmp0 = group0, tmp1 = group1;
        if (tmp0.size() % 2 == 1) tmp0.pop_back();
        if (tmp1.size() % 2 == 1) tmp1.pop_back();

        vint v;
        for (ll x : tmp0) v.push_back(x);
        for (ll x : tmp1) v.push_back(x);

        for (int i = 0; i < K - 1; i++) {
            q2.push_back(v[i]);
        }
    }

    vint ans(N);

    rep(i, K - 1) {
        q2.push_back(i);
        cout << "?";
        for (ll x : q2) cout << " " << x + 1;
        cout << '\n';
        cout << flush;
        q2.pop_back();

        int T;
        cin >> T;
        if (T == -1) return;
        ans[i] = T;
    }

    int parity = 0;
    rep(i, K - 1) parity ^= ans[i];

    for (ll id : group0) ans[id] = parity;
    for (ll id : group1) ans[id] = parity ^ 1;

    cout << "! ";
    print(ans);
    cout << flush;
}
