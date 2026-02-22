// https://atcoder.jp/contests/abc446/tasks/abc446_c
// Sat 21 Feb 2026 09:08:09 PM JST
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

    auto cal = []() -> void {
        ll N, D;
        cin >> N >> D;
        vll A(N), B(N);
        rep(i, N) cin >> A[i];
        rep(i, N) cin >> B[i];

        // num, day
        using P = pair<ll, ll>;
        deque<P> deq;

        rep(i, N) {
            deq.push_back({A[i], i});

            ll b = B[i];
            while (b) {
                ll mi = min(b, deq.front().first);
                b -= mi;
                deq.front().first -= mi;
                if (deq.front().first == 0) deq.pop_front();
            }

            while (deq.size() && deq.front().second + D <= i) deq.pop_front();
        }

        ll ans = 0;
        for (auto [num, d] : deq) ans += num;
        cout << ans << endl;
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
