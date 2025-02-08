/*https://atcoder.jp/contests/abc320/tasks/abc320_d*/
/*2025年02月06日 21時20分16秒*/
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

struct Person {
    ll id, x, y;
};

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<Person>> graph(N);
    rep(i, M) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        a--, b--;
        graph[a].push_back({b, x, y});
        graph[b].push_back({a, -x, -y});
    }

    vector<Person> pos(N);
    pos[0] = {0, 0, 0};
    rep(i, N) pos[i].id = i;
    vint visited(N, 0);
    visited[0] = 1;

    queue<Person> que;
    que.push(pos[0]);
    while (que.size()) {
        auto [id, x, y] = que.front();
        que.pop();

        for (auto [nid, nx, ny] : graph[id]) {
            if (visited[nid]) {
                continue;
            }
            visited[nid] = 1;
            pos[nid].x = x + nx;
            pos[nid].y = y + ny;
            que.push(pos[nid]);
        }
    }

    for (auto [id, x, y] : pos) {
        if (!visited[id]) {
            cout << "undecidable" << endl;
        } else {
            cout << x << ' ' << y << endl;
        }
    }
}
