// https://atcoder.jp/contests/abc313/tasks/abc313_e
// Wed 18 Feb 2026 12:11:21 AM JST
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

    ll N;
    string S;
    cin >> N >> S;
    rep(i, N - 1) {
        if (S[i] != '1' && S[i + 1] != '1') {
            cout << -1 << endl;
            return;
        }
    }

    using P = pair<mint, ll>;
    deque<P> deq;
    ll cnt = 0;
    rep(i, N) {
        if (S[i] != '1') {
            deq.push_back({cnt, S[i] - '0'});
            cnt = 0;
        } else {
            cnt++;
        }
    }
    if (cnt) deq.push_back({cnt, 1});

    mint ans = 0;
    while (deq.size()) {
        auto [num, d] = deq.back();
        deq.pop_back();
        if (num == 0) {
            break;
        }

        if (d != 1)
            ans += num + (d - 1) * (ans + 1);
        else
            ans += num - 1;
        if (deq.size()) ans++;
    }

    cout << ans.val() << endl;
}
