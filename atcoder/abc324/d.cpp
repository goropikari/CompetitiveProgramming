/*https://atcoder.jp/contests/abc324/tasks/abc324_d*/
/*2025年02月07日 20時51分48秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <string>
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
    int n;
    string s;
    cin >> n >> s;

    vll cnt(10, 0);
    rep(i, n) cnt[s[i] - '0']++;

    ll ans = 0;
    rep(i, 1e7 + 1) {
        ll sq = i * i;
        string t = to_string(sq);
        vll v(10, 0);
        if (t.size() < n) {
            v[0] += n - t.size();
        }
        for (char c : t)
            v[c - '0']++;
        ans += (v == cnt);
    }
    cout << ans << endl;
}
