/*https://atcoder.jp/contests/abc394/tasks/abc394_e*/
/*2025年02月22日 21時20分21秒*/
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

int n;
vvll dist;
vector<string> labels;
vvint graph;

int sub2id(int i, int j) {
    return i * n + j;
}

pair<int, int> id2sub(int x) {
    return {x / n, x % n};
}

ll dfs(int now, int goal, string s) {
    if (s.size() >= 200) {
        return INF;
    }

    ll ans = INF;

    for (int nx : graph[now]) {
        s.push_back(labels[now][nx]);
        if (nx == goal) {
            string t = s;
            reverse(all(t));
            if (t == s) {
                return s.size();
            }
        }
        chmin(ans, dfs(nx, goal, s));
        s.pop_back();
    }

    return ans;
}

void solve() {
    cin >> n;
    labels.resize(n);
    rep(i, n) cin >> labels[i];

    graph.resize(n);
    dist = vvll(n, vll(n));
    rep(i, n) rep(j, n) {
        if (labels[i][j] != '-') {
            dist[i][j] = 1;
            graph[i].push_back(j);
        }
    }

    vvll ans(n, vll(n, -1));
    rep(i, n) ans[i][i] = 0;
    rep(from, n) {
        rep(to, n) {
            if (from == to) {
                continue;
            }
            if (dist[from][to] == INF) {
                continue;
            }
            ll res = dfs(from, to, "");
            if (res == INF)
                ans[from][to] = -1;
            else
                ans[from][to] = res;
        }
    }

    for (auto v : ans)
        print(v);
}
