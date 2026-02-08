// https://atcoder.jp/contests/abc444/tasks/abc444_e
// Sat 07 Feb 2026 09:57:05 PM JST
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

    ll N, D;
    cin >> N >> D;
    vll A(N);
    rep(i, N) cin >> A[i];

    // number, index
    map<ll, ll> S;
    S[-INF] = S[INF] = -1;  // sentinel

    int l = 0;

    auto del_neigh = [&](ll x) -> void {
        ll tmpl = -1;
        auto it = S.lower_bound(x);
        auto [num1, index1] = *it;
        if (abs(num1 - x) < D) chmax(tmpl, index1);

        it--;
        auto [num2, index2] = *it;
        if (abs(num2 - x) < D) chmax(tmpl, index2);

        while (l <= tmpl) {
            S.erase(A[l]);
            l++;
        }
    };

    ll ans = 0;

    rep(r, N) {
        del_neigh(A[r]);
        S[A[r]] = r;
        ans += r - l + 1;
    }

    cout << ans << endl;
}
