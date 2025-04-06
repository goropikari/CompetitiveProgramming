// https://atcoder.jp/contests/past15-open/tasks/past202306_e
// 2025年04月07日 01時00分21秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
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
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vll a(n);
    rep(i, n) cin >> a[i];

    vint v;

    auto dfs = [&](auto dfs, int used) -> void {
        if (__builtin_popcount(used) == k) {
            v.push_back(used);
            return;
        }

        int id = -1;
        rep(i, n) {
            if ((used >> i) & 1)
                id = i;
        }
        rep2(i, id + 1, n) {
            dfs(dfs, used | (1 << i));
        }
    };

    dfs(dfs, 0);

    ll ans = 0;
    for (int used : v) {
        rep(i, n) {
            if ((used >> i) & 1)
                ans += a[i];
        }
    }
    cout << ans << endl;
}
