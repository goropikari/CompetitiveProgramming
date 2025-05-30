/*https://atcoder.jp/contests/abc323/tasks/abc323_d*/
/*2025年02月06日 22時04分34秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <queue>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;

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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ll N;
    cin >> N;
    vll S(N), C(N);
    rep(i, N) cin >> S[i] >> C[i];

    map<ll, ll> mp;
    rep(i, N) mp[S[i]] = C[i];

    ll ans = 0;
    while (mp.size()) {
        auto it = mp.begin();
        ll k = it->first, v = it->second;
        if (v % 2 == 1)
            ans++;

        if (v > 1)
            mp[k * 2] += v / 2;

        mp.erase(mp.begin());
    }
    cout << ans << endl;
}
