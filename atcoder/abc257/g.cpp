// https://atcoder.jp/contests/abc257/tasks/abc257_g
// Mon 09 Feb 2026 03:05:45 AM JST
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;

    int n = T.size();
    vint Z;
    {
        vint tmp = z_algorithm(S + "$" + T);  // T の区間に |S| 以上の長さが出ないように $ を挟む
        rep(i, n) Z.push_back(tmp[S.size() + i + 1]);
    }

    // min, sum
    using P = pair<ll, ll>;

    auto op = [](P a, P b) -> P {
        return {max(a.first, b.first), min(a.second, b.second)};
    };

    auto e = []() -> P {
        return {0, INF};
    };

    segtree<P, op, e> seg(n + 1);
    seg.set(n, {1, 0});

    for (int i = n - 1; i >= 0; i--) {
        if (!Z[i]) continue;
        P p = seg.prod(i + 1, min(i + Z[i] + 1, n + 1));
        seg.set(i, {p.first, p.second + 1});
    }

    P x = seg.get(0);
    ll ans = -1;
    if (x.first) ans = x.second;
    cout << ans << endl;
}
