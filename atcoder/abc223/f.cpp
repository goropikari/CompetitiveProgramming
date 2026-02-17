// https://atcoder.jp/contests/abc223/tasks/abc223_f
// Mon 16 Feb 2026 09:57:08 AM JST
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

    ll N, Q;
    string S;
    cin >> N >> Q >> S;

    using P = pair<ll, ll>;
    auto op = [](P a, P b) -> P {
        ll m = min(a.second, b.first);
        return {a.first + b.first - m, b.second + a.second - m};
    };

    auto e = []() -> P {
        return {0, 0};
    };

    segtree<P, op, e> seg(N);
    rep(i, N) {
        if (S[i] == ')')
            seg.set(i, {1, 0});
        else
            seg.set(i, {0, 1});
    }

    while (Q--) {
        ll t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        if (t == 1) {
            P left = seg.get(l), right = seg.get(r);
            swap(left, right);
            seg.set(l, left);
            seg.set(r, right);
        } else {
            P ret = seg.prod(l, r + 1);
            yesno(ret.first == 0 && ret.second == 0);
        }
    }
}
