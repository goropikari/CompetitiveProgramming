// https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c
// Sun 25 Jan 2026 12:34:34 PM JST
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

    ll N, M;
    cin >> N >> M;

    vll P(N);
    rep(i, N) cin >> P[i];

    sort(all(P));

    ll ans = 0;

    rep(i, N) {
        if (P[i] <= M) chmax(ans, P[i]);
    }

    vll pp;
    rep(i, N) rep2(j, i, N) pp.push_back(P[i] + P[j]);
    sort(all(pp));
    rep(i, (ll)pp.size()) {
        if (pp[i] <= M) chmax(ans, pp[i]);

        {
            auto it = upper_bound(all(P), M - pp[i]);
            if (it != P.begin()) {
                it--;
                chmax(ans, pp[i] + *it);
            }
        }
        {
            auto it = upper_bound(all(pp), M - pp[i]);
            if (it != pp.begin()) {
                it--;
                chmax(ans, pp[i] + *it);
            }
        }
    }

    cout << ans << endl;
}
