// https://atcoder.jp/contests/abc423/tasks/abc423_c
// 2025年09月14日 21時07分39秒
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
void chmin(T& a, T b) {
    a = min(a, b);
}
template <typename T>
void chmax(T& a, T b) {
    a = max(a, b);
}

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

void yesno(bool x) {
    cout << (x ? "Yes" : "No") << '\n';
}

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

// ceil(a/b)
ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

// floor(a/b)
ll floor(ll a, ll b) {
    return a / b;
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, R;
    cin >> N >> R;

    vint keys(N);
    rep(i, N) cin >> keys[i];

    fenwick_tree<ll> fw(N);
    rep(i, N) fw.add(i, keys[i]);

    ll lid = INF, rid = -1;

    rep(i, R) {
        if (keys[i] == 0) {
            lid = i;
            break;
        }
    }
    rep2(i, R, N) {
        if (keys[i] == 0) rid = i;
    }

    ll ans = 0;

    if (lid != INF) {
        ll w = R - lid;
        ll cnt = fw.sum(lid, R);
        ans += w + cnt;
    }

    if (rid != -1) {
        ll w = rid + 1 - R;
        ll cnt = fw.sum(R, rid + 1);
        ans += w + cnt;
    }
    cout << ans << endl;
}
