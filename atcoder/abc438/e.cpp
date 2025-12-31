// https://atcoder.jp/contests/abc438/tasks/abc438_e
// Tue 30 Dec 2025 01:30:14 PM JST
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

    ll N, Q;
    cin >> N >> Q;
    vll A(N);
    rep(i, N) {
        cin >> A[i];
        A[i]--;
    }

    int upper = 31;
    vvll buckets(upper, vll(N, 0)), water(upper, vll(N, 0));
    rep(i, N) {
        buckets[0][i] = A[i];
        water[0][i] += i + 1;
    }
    rep2(d, 1, upper) {
        rep(i, N) {
            int j = buckets[d - 1][i];
            buckets[d][i] = buckets[d - 1][j];
            water[d][i] = water[d - 1][i] + water[d - 1][j];
        }
    }

    auto cal = [&]() -> void {
        ll t, b;
        cin >> t >> b;
        b--;
        ll ans = 0;
        int now = b;
        rep(i, upper) {
            if ((t >> i) & 1) {
                ans += water[i][now];
                now = buckets[i][now];
            }
        }
        cout << ans << endl;
    };

    rep(i, Q) {
        cal();
    }
}
