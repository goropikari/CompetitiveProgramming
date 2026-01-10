// https://atcoder.jp/contests/abc440/tasks/abc440_c
// Sat 10 Jan 2026 09:03:05 PM JST
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

template <typename T>
struct Cumsum {
    vector<T> data;

    Cumsum(vector<T> v) {
        int n = v.size();
        data.resize(n + 1);

        data[0] = 1;
        rep(i, n) {
            data[i + 1] = data[i] + v[i];
        }
    }

    // sum of range [l,r)
    ll sum(int l, int r) {
        return data[r] - data[l];
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto cal = []() -> void {
        ll N, W;
        cin >> N >> W;
        vll C(N + W * 2);
        rep(i, N) cin >> C[i];
        N += W * 2;

        Cumsum cm(C);

        ll ans = INF;
        rep2(fin, 1, W * 2 + 1) {
            ll tmp = 0;
            for (ll r = fin; r < N; r += W * 2) {
                tmp += cm.sum(max(0ll, r - W), r);
            }
            chmin(ans, tmp);
        }
        cout << ans << endl;
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
