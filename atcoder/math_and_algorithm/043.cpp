// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_am
/*2025年01月12日 02時31分43秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <numeric>
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

vvll graph;
vector<bool> visited;

void dfs(int now, int p) {
    visited[now] = true;
    for (int nx : graph[now]) {
        if (nx == p)
            continue;
        if (visited[nx])
            continue;
        dfs(nx, now);
    }
}

void solve() {
    int N, M;
    cin >> N >> M;
    graph = vvll(N);
    visited = vector<bool>(N, false);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, -1);

    if (accumulate(all(visited), 0) == N) {
        puts("The graph is connected.");
    } else {
        puts("The graph is not connected.");
    }
}
