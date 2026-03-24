// https://atcoder.jp/contests/awc0031/tasks/awc0031_d
// Tue 24 Mar 2026 01:25:18 AM JST
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
void print(vector<T> v, char delim = ' ') {
    int n = v.size();
    rep(i, n) {
        if (i == 0)
            cout << v[i];
        else
            cout << delim << v[i];
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

    ll N, M;
    cin >> N >> M;
    vll L(N), R(M);
    rep(i, N) cin >> L[i];
    rep(i, M) cin >> R[i];

    sort(rall(L));
    sort(all(R));

    vll cnt(N);
    rep(x, N) {
        cnt[x] = R.end() - lower_bound(all(R), x + 1);
    }

    vll rem = cnt;

    ll x = 0, i = 0;
    deque<ll> deq;
    for (ll l : L) deq.pb(l);
    while (deq.size()) {
        ll l = deq.front();
        deq.pop_front();
        if (i + l <= cnt[x]) {
            i += l;
            rem[x] -= l;
        } else {
            l -= rem[x];
            rem[x] = 0;
            if (x + 1 == N) break;
            x++;
            if (i == 0) continue;
            i = min({cnt[x], i - 1, l});
            rem[x] -= i;
        }
        if (rem[x] == 0) {
            if (x + 1 == N) break;
            x++;
            i = 0;
        }
    }

    ll sum = accumulate(all(rem), 0ll);
    yesno(sum == 0);
}
