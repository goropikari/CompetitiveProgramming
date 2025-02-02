/*https://atcoder.jp/contests/abc318/tasks/abc318_e*/
/*2025年02月02日 01時37分14秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <numeric>
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
    vll A(N);
    rep(i, N) cin >> A[i];

    map<ll, vll> mp;
    rep(i, N) {
        mp[A[i]].push_back(i);
    }

    ll ans = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        auto v = it->second;
        if (v.size() < 2)
            continue;

        rep(i, v.size() - 1) {
            ans += (v[i + 1] - v[i] - 1) * (i + 1) * (v.size() - i - 1);
        }
    }
    cout << ans << endl;
}
