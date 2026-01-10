// https://atcoder.jp/contests/abc365/tasks/abc365_e
// Mon 05 Jan 2026 10:33:35 PM JST
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    ll ans = 0;
    rep(d, 30) {
        vll v;
        rep(i, N) {
            v.push_back((A[i] >> d) & 1);
        }

        ll x = v[0];
        vll tmp;
        rep2(i, 1, N) {
            x ^= v[i];
            tmp.push_back(x);
        }
        // print(tmp);

        ll one = 0, zero = 0;
        one = accumulate(all(tmp), 0ll);
        zero = (ll)tmp.size() - one;

        ll cnt = one;
        int flag = 0;
        rep(i, N - 1) {
            if (v[i] == 1) {
                if ((flag ^ tmp[i]) == 1) {
                    one--;
                } else {
                    zero--;
                }
                swap(one, zero);
                flag = 1 - flag;
            } else {
                if ((flag ^ tmp[i]) == 1) {
                    one--;
                } else {
                    zero--;
                }
            }
            cnt += one;
        }
        ans += (1ll << d) * cnt;
    }
    cout << ans << endl;
}
