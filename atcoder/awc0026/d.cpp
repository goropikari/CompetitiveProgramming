// https://atcoder.jp/contests/awc0026/tasks/awc0026_d
// Tue 17 Mar 2026 11:32:26 PM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define pb push_back
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

template <typename T>
bool chmin(T& a, T b) {
    bool change = a > b;
    a = min(a, b);
    return change;
}
template <typename T>
bool chmax(T& a, T b) {
    bool change = a < b;
    a = max(a, b);
    return change;
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

template <typename T>
void vprint(vector<T> v) {
    for (auto x : v) cout << x << '\n';
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

    ll N, K;
    cin >> N >> K;
    vll L(N), R(N);
    rep(i, N) cin >> L[i] >> R[i];

    vll pos;
    rep(i, N) {
        pos.pb(L[i]);
        pos.pb(R[i]);
    }
    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());

    ll sz = pos.size();
    vll draw(sz + 1);
    rep(i, N) {
        int l = lower_bound(all(pos), L[i]) - pos.begin();
        int r = lower_bound(all(pos), R[i]) - pos.begin();
        draw[l]++;
        draw[r]--;
    }

    ll ans = 0;
    rep(i, sz) draw[i + 1] += draw[i];
    int i = 0;
    while (i < sz) {
        if (draw[i] < K) {
            i++;
            continue;
        }
        int s = i;
        while (i < sz && draw[i] >= K) {
            i++;
        }
        ans += pos[i] - pos[s];
        i++;
    }
    // print(pos);
    // print(draw);
    cout << ans << endl;
}
