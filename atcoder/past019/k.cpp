// https://atcoder.jp/contests/past19-open/tasks/past19_k
// 2025年03月30日 19時25分26秒
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

    int N, K;
    cin >> N >> K;
    vvint graph(N);
    rep(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vll A(N);
    rep(i, N) cin >> A[i];

    // dp[i][j][k]:
    // i: node 番号
    // j: node i を使うかどうか
    // k: k 個の頂点を選んだときの総和の最大値
    vector<vvll> dp(N, vvll(2, vll(K + 1, -INF)));

    auto dfs = [&](auto dfs, int now, int p) -> void {
        for (int nx : graph[now]) {
            if (nx == p)
                continue;
            dfs(dfs, nx, now);
        }

        dp[now][0][0] = 0;
        dp[now][1][1] = A[now];

        for (int nx : graph[now]) {
            if (nx == p)
                continue;
            {
                // now 使用
                vll tmp = dp[now][1];
                vll v = dp[nx][0];

                rep(i, K + 1) {
                    rep(j, K + 1) {
                        if (i + j <= K) {
                            if (dp[now][1][i] >= 0 && v[j] >= 0)
                                chmax(tmp[i + j], dp[now][1][i] + v[j]);
                        }
                    }
                }
                dp[now][1] = tmp;
            }
            {
                // now 不使用
                vll tmp = dp[now][0];
                rep(i, K + 1) {
                    rep(j, K + 1) {
                        if (i + j <= K) {
                            if (dp[now][0][i] >= 0 && dp[nx][0][j] >= 0)
                                chmax(tmp[i + j], dp[now][0][i] + dp[nx][0][j]);
                            if (dp[now][0][i] >= 0 && dp[nx][1][j] >= 0)
                                chmax(tmp[i + j], dp[now][0][i] + dp[nx][1][j]);
                        }
                    }
                }
                dp[now][0] = tmp;
            }
        }
    };

    dfs(dfs, 0, -1);
    ll ans = max(dp[0][0][K], dp[0][1][K]);
    if (ans < 0)
        ans = -1;
    cout << ans << endl;
}
