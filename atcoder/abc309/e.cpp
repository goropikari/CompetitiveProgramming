/*https://atcoder.jp/contests/abc309/tasks/abc309_e*/
/*2025年03月16日 23時16分07秒*/
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vvint graph(n);
    rep2(i, 1, n) {
        int p;
        cin >> p;
        p--;
        graph[p].push_back(i);
    }

    vint prop(n, -1);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        chmax(prop[x], y);
    }

    auto dfs = [&](auto dfs, int now) -> void {
        for (int nx : graph[now]) {
            chmax(prop[nx], prop[now] - 1);
            dfs(dfs, nx);
        }
    };

    dfs(dfs, 0);

    ll ans = 0;
    rep(i, n) ans += prop[i] != -1;
    cout << ans << endl;
}
