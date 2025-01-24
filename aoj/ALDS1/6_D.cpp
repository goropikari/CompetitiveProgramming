// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_D
/*2025年01月23日 00時44分35秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
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
    cin >> n;
    vll w(n, 0);
    rep(i, n) cin >> w[i];

    vector<ll> p;
    p = w;
    sort(all(p));
    ll mi = p[0];

    map<int, int> mp;
    rep(i, n) mp[p[i]] = i;

    ll ans = 0;

    vint visited(n, false);
    rep(i, n) {
        if (visited[i])
            continue;
        int cur = i, cnt = 0;
        ll sum = 0, low = w[i];
        while (true) {
            visited[cur] = 1;
            sum += w[cur];
            chmin(low, w[cur]);
            cnt++;
            cur = mp[w[cur]];
            if (visited[cur])
                break;
        }
        ans += min(sum + (cnt - 2) * low,
                   2 * (low + mi) + sum - low + mi + (cnt - 2) * mi);
    }
    cout << ans << endl;
}
