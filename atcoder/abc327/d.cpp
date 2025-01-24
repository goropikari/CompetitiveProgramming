/*https://atcoder.jp/contests/abc327/tasks/abc327_d*/
/*2025年01月24日 02時24分05秒*/
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
    ll N, M;
    cin >> N >> M;

    vint A(M), B(M);
    rep(i, M) cin >> A[i];
    rep(i, M) cin >> B[i];

    rep(i, M) if (A[i] == B[i]) {
        yesno(false);
        return;
    }

    set<pair<int, int>> edge;
    rep(i, M) {
        int a = A[i] - 1, b = B[i] - 1;
        if (a > b)
            swap(a, b);
        edge.insert({a, b});
    }

    vvint graph(N);
    for (auto [u, v] : edge) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vint col(N, -1);
    rep(i, N) {
        if (col[i] != -1)
            continue;

        queue<int> que;
        que.push(i);

        while (que.size()) {
            int now = que.front();
            que.pop();

            if (col[now] == -1)
                col[now] = 0;

            for (int nx : graph[now]) {
                if (col[nx] == col[now]) {
                    yesno(false);
                    return;
                }
                if (col[nx] == -1) {
                    col[nx] = 1 - col[now];
                    que.push(nx);
                }
            }
        }
    }

    yesno(true);
}
