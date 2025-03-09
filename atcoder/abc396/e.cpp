/*https://atcoder.jp/contests/abc396/tasks/abc396_e*/
/*2025年03月09日 12時55分16秒*/
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    rep(i, m) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        graph[x].emplace_back(y, z);
        graph[y].emplace_back(x, z);
    }

    vint a(n), used(n);

    auto dfs = [&](auto dfs, int now, vint& path) -> void {
        used[now] = 1;
        path.push_back(now);
        for (auto [to, w] : graph[now]) {
            if (used[to]) {
                if (a[to] != (a[now] ^ w)) {
                    cout << -1 << '\n';
                    exit(0);
                }
                continue;
            }
            a[to] = a[now] ^ w;
            dfs(dfs, to, path);
        }
    };

    vvint stock;
    rep(i, n) {
        if (used[i])
            continue;
        vint path;
        dfs(dfs, i, path);
        stock.push_back(path);
    }

    vint na(n);
    for (auto path : stock) {
        int sz = path.size();
        vint cnt(60);
        for (int x : path) {
            rep(i, 60) {
                cnt[i] += ((a[x] >> i) & 1);
            }
        }
        rep(i, 60) {
            if (cnt[i] > sz - cnt[i]) {  // 1 の数が多いから 1 スタートのほうが良かった場合
                // i 桁目を全て bit flip させる
                for (int x : path) {
                    a[x] ^= 1ll << i;
                }
            }
        }
    }
    print(a);
}
