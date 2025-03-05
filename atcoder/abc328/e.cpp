/*https://atcoder.jp/contests/abc328/tasks/abc328_e*/
/*2025年03月05日 22時19分56秒*/
#include <atcoder/all>
using namespace atcoder;
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

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

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

    ll n, m, k;
    cin >> n >> m >> k;

    vector<tuple<ll, ll, ll>> es;
    rep(i, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        es.emplace_back(u, v, w);
    }

    ll ans = INF;
    auto dfs = [&](auto dfs, int depth, vint& used) {
        if (used.size() == n - 1) {
            dsu uf(n);
            ll sum = 0;
            for (int i : used) {
                auto [u, v, w] = es[i];
                if (uf.same(u, v))
                    return;
                uf.merge(u, v);
                sum += w;
                sum %= k;
            }
            chmin(ans, sum);
            return;
        }
        if (depth == m) {
            return;
        }

        dfs(dfs, depth + 1, used);
        used.push_back(depth);
        dfs(dfs, depth + 1, used);
        used.pop_back();
    };

    vint v;
    dfs(dfs, 0, v);
    cout << ans << endl;
}
