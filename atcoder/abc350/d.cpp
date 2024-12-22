/*https://atcoder.jp/contests/abc350/tasks/abc350_d*/
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<ll,ll>;
using P = pair<int, int>;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;
// const ll MOD = (ll)1e9+9;
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
    int N, M;
    cin >> N >> M;

    dsu uf(N);
    vector<pair<int, int>> edges;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges.push_back({a, b});
        uf.merge(a, b);
    }

    vvint groups = uf.groups();
    map<ll, ll> mp;
    for (auto [a, b] : edges) {
        mp[uf.leader(a)]++;
    }

    ll ans = 0;
    for (vint& v : groups) {
        ll n = v.size();
        ans += n * (n - 1) / 2 - mp[uf.leader(v[0])];
    }
    cout << ans << endl;
}
