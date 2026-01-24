// https://atcoder.jp/contests/abc158/tasks/abc158_e
// Sat 24 Jan 2026 02:52:47 PM JST
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

void naive() {
    ll N, P;
    string S;
    cin >> N >> P >> S;

    ll ans = 0;
    rep(i, N) rep2(j, i, N) {
        int128 x = 0;
        rep2(k, i, j + 1) {
            x *= 10;
            x += S[k] - '0';
        }
        if (x % P == 0) ans++;
    }
    cout << ans << endl;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, P;
    string S;
    cin >> N >> P >> S;

    reverse(all(S));

    auto two = [&]() -> ll {
        ll ans = 0;
        rep(i, N) {
            ll x = S[i] - '0';
            if (x % 2 == 0) ans += N - i;
        }
        return ans;
    };

    auto five = [&]() -> ll {
        ll ans = 0;
        rep(i, N) {
            ll x = S[i] - '0';
            if (x % 5 == 0) ans += N - i;
        }
        return ans;
    };

    auto other = [&]() -> ll {
        vll cm(N + 1);
        ll ten = 1;
        rep(i, N) {
            cm[i + 1] = cm[i] + (S[i] - '0') * ten;
            cm[i + 1] %= P;
            ten *= 10;
            ten %= P;
        }

        ll ans = 0;
        fenwick_tree<ll> fw(P);
        rep(i, N + 1) {
            fw.add(cm[i], 1);
        }

        rep(i, P) {
            ll x = fw.sum(i, i + 1);
            ans += x * (x - 1) / 2;
        }
        return ans;
    };

    ll ans = 0;
    if (P == 2)
        ans = two();
    else if (P == 5)
        ans = five();
    else
        ans = other();

    cout << ans << endl;
}
