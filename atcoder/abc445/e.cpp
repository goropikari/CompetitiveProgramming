// https://atcoder.jp/contests/abc445/tasks/abc445_e
// Sat 14 Feb 2026 10:08:19 PM JST
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
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

    // ll M = (ll)1e7 + 1;
    // vll lpf(M);
    // iota(all(lpf), 0ll);
    // rep2(i, 2, M) {
    //     for (ll j = i + i; j < M; j += i) {
    //         if (lpf[j] > i)
    //             lpf[j] = i;
    //     }
    // }

    ll M = (ll)1e7 + 1;
    vll lpf(M, -1);
    vll primes;
    rep2(d, 2, M) {
        if (lpf[d] < 0) {
            lpf[d] = d;
            primes.push_back(d);
        }
        for (ll p : primes) {
            if (p * d > M || p > lpf[d]) break;
            lpf[p * d] = p;
        }
    }

    auto cal = [&]() -> void {
        ll N;
        cin >> N;
        vll A(N);
        rep(i, N) cin >> A[i];

        map<ll, ll> e1, e2;
        for (ll x : A) {
            while (x != 1) {
                ll p = lpf[x], cnt = 0;

                while (x % p == 0) {
                    cnt++;
                    x /= p;
                }

                if (cnt > e1[p]) {
                    e2[p] = e1[p];
                    e1[p] = cnt;
                } else if (cnt > e2[p]) {
                    e2[p] = cnt;
                }
            }
        }

        mint cm = 1;
        for (auto [p, cnt] : e1) {
            cm *= ((mint)p).pow(cnt);
        }

        vll ans;
        for (ll x : A) {
            mint mul = cm;
            while (x != 1) {
                ll p = lpf[x], cnt = 0;

                while (x % p == 0) {
                    cnt++;
                    x /= p;
                }

                if (cnt == e1[p]) {
                    mul /= (mint(p).pow(e1[p] - e2[p]));
                }
            }
            ans.push_back(mul.val());
        }
        print(ans);
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
