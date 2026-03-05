// https://atcoder.jp/contests/abc312/tasks/abc312_f
// Tue 24 Feb 2026 10:00:43 AM JST
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

    vll need, needless, opener;
    rep(i, N) {
        ll t, x;
        cin >> t >> x;
        if (t == 0) needless.pb(x);
        if (t == 1) need.pb(x);
        if (t == 2) opener.pb(x);
    }

    sort(rall(needless));
    sort(rall(need));
    sort(rall(opener));
    rep(i, (ll)opener.size() - 1) {
        opener[i + 1] += opener[i];
    }
    rep(i, (ll)needless.size() - 1) {
        needless[i + 1] += needless[i];
    }
    rep(i, (ll)need.size() - 1) {
        need[i + 1] += need[i];
    }

    ll ans = 0;
    if (needless.size()) {
        ans = needless[min(M - 1, (ll)needless.size() - 1)];
    }

    rep(i, (ll)need.size()) {
        ll ncan = i + 1;
        if (!opener.size()) break;
        auto it = lower_bound(all(opener), ncan);
        if (it == opener.end()) break;

        // i+1 個の缶切りが必要な缶を開けるために必要な缶切りの個数
        ll need_opener = it - opener.begin() + 1;
        if (need_opener + ncan > M) continue;

        ll sum = need[i];
        ll m = M - need_opener - ncan;
        if (m > 0) {  // 缶切り不要な缶が使える場合
            int id = min(m - 1, (ll)needless.size() - 1);
            sum += needless[id];
        }
        chmax(ans, sum);
    }
    cout << ans << endl;
}
