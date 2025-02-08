/*https://atcoder.jp/contests/abc302/tasks/abc302_e*/
/*2025年02月04日 23時23分00秒*/
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
    ll N, Q;
    cin >> N >> Q;

    vector<set<int>> graph(N);

    int cnt = N;

    rep(i, Q) {
        int x;
        cin >> x;
        if (x == 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            if (graph[u].size() == 0)
                cnt--;
            if (graph[v].size() == 0)
                cnt--;

            graph[u].insert(v);
            graph[v].insert(u);
        } else {
            int y;
            cin >> y;
            y--;
            for (int u : graph[y]) {
                graph[u].erase(y);
                if (graph[u].size() == 0)
                    cnt++;
            }
            if (graph[y].size() != 0)
                cnt++;
            graph[y] = set<int>();
        }
        cout << cnt << endl;
    }
}
