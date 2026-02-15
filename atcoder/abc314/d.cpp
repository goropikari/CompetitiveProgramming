// https://atcoder.jp/contests/abc314/tasks/abc314_d
// Wed 11 Feb 2026 12:57:44 AM JST
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

    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    // state
    // -1: 小文字
    // 0: そのまま
    // 1: 大文字
    int state = 0;

    set<int> diff;

    while (Q--) {
        int t, x;
        char c;
        cin >> t >> x >> c;
        x--;

        if (t == 1) {
            S[x] = c;
            diff.erase(x);
            if (state != 0) diff.insert(x);
        } else if (t == 2) {
            state = -1;
            diff.clear();
        } else {
            state = 1;
            diff.clear();
        }
    }

    if (state == 1) {
        rep(i, N) {
            if (diff.count(i)) continue;
            if (islower(S[i])) S[i] ^= 32;
        }
    }
    if (state == -1) {
        rep(i, N) {
            if (diff.count(i)) continue;
            if (isupper(S[i])) S[i] ^= 32;
        }
    }

    cout << S << endl;
}
