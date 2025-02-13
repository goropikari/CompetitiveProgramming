/*https://atcoder.jp/contests/abc349/tasks/abc349_d*/
/*2025年02月13日 23時34分18秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
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
    ll l, r;
    cin >> l >> r;

    vector<pair<ll, ll>> ans;
    while (r - l >= 1) {
        ll cnt = 0;
        while ((l & (1LL << cnt)) == 0 && cnt <= 60)
            cnt++;

        while (l + (1LL << cnt) > r)
            cnt--;

        ans.push_back({l, l + (1LL << cnt)});
        l += 1LL << cnt;
    }

    cout << ans.size() << endl;
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << endl;
    }
}
