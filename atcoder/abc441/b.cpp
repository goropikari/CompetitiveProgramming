// https://atcoder.jp/contests/abc441/tasks/abc441_b
// Sat 17 Jan 2026 09:02:16 PM JST
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

    string S, T;
    cin >> S >> T;

    ll Q;
    cin >> Q;

    set<char> takahashi, aoki;
    for (char c : S) takahashi.insert(c);
    for (char c : T) aoki.insert(c);

    rep(i, Q) {
        string w;
        cin >> w;

        ll state = 0;
        {
            int ok = 1;
            for (char c : w) {
                if (!takahashi.count(c)) ok = 0;
            }
            if (ok) state += 1;
        }
        {
            int ok = 1;
            for (char c : w) {
                if (!aoki.count(c)) ok = 0;
            }
            if (ok) state += 2;
        }

        string ans = "Unknown";
        if (state == 1) ans = "Takahashi";
        if (state == 2) ans = "Aoki";
        cout << ans << endl;
    }
}
