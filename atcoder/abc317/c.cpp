/*https://atcoder.jp/contests/abc317/tasks/abc317_c*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <unistd.h>
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

ll ans = 0;
vint visited;
map<pair<ll, ll>, ll> cost;

void dfs(vvint& graph, int now, int p, ll sum) {
    chmax(ans, sum);
    visited[now] = 1;
    for (auto nx : graph[now]) {
        if (visited[nx])
            continue;
        if (nx == p)
            continue;
        dfs(graph, nx, now, sum + cost[{now, nx}]);
    }
    visited[now] = 0;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vll A(M), B(M), C(M);
    vvint graph(N);
    visited.resize(N);
    rep(i, M) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--, B[i]--;
        graph[A[i]].push_back(B[i]);
        graph[B[i]].push_back(A[i]);
        cost[{A[i], B[i]}] = C[i];
        cost[{B[i], A[i]}] = C[i];
    }

    rep(i, N) dfs(graph, i, -1, 0);
    cout << ans << endl;
}
