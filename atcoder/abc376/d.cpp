/*https://atcoder.jp/contests/abc376/tasks/abc376_d*/
/*2025年01月27日 23時58分26秒*/
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
    int N, M;
    cin >> N >> M;

    vvint graph(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
    }

    vll dist(N, INF);
    dist[0] = 0;

    queue<int> que;
    que.push(0);
    // while (que.size()) {
    //     int now = que.front();
    //     que.pop();
    //
    //     for (int nx : graph[now]) {
    //         if (nx == 0) {
    //             cout << dist[now] + 1 << endl;
    //             return;
    //         }
    //         if (dist[nx] != INF)
    //             continue;
    //
    //         dist[nx] = dist[now] + 1;
    //         que.push(nx);
    //     }
    // }

    vint visited(N, 0);
    visited[0] = 1;
    while (que.size()) {
        int now = que.front();
        que.pop();

        for (int nx : graph[now]) {
            if (nx == 0) {
                cout << dist[now] + 1 << endl;
                return;
            }
            if (visited[nx])
                continue;
            visited[nx] = 1;

            dist[nx] = dist[now] + 1;
            que.push(nx);
        }
    }

    // bug
    // vint visited(N, 0);
    // while (que.size()) {
    //     int now = que.front();
    //     que.pop();
    //
    //     if (visited[now])
    //         continue;
    //     visited[now] = 1;
    //
    //     for (int nx : graph[now]) {
    //         if (nx == 0) {
    //             cout << dist[now] + 1 << endl;
    //             return;
    //         }
    //         if (visited[nx])
    //             continue;
    //
    //         dist[nx] = dist[now] + 1;
    //         que.push(nx);
    //     }
    // }

    cout << -1 << endl;
}
