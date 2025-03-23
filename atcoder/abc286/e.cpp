/*https://atcoder.jp/contests/abc286/tasks/abc286_e*/
/*2025年03月24日 02時08分39秒*/
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

    int n;
    cin >> n;
    vll prices(n);
    rep(i, n) cin >> prices[i];

    vector<string> s(n);
    rep(i, n) cin >> s[i];

    vvll dist(n, vll(n, INF));
    rep(i, n) dist[i][i] = 0;
    vvll value(n, vll(n));
    rep(i, n) {
        rep(j, n) {
            if (s[i][j] == 'Y') {
                dist[i][j] = 1;
                value[i][j] = prices[i] + prices[j];
            }
        }
    }

    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    value[i][j] = value[i][k] + value[k][j] - prices[k];
                }
                if (dist[i][j] == dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    chmax(value[i][j], value[i][k] + value[k][j] - prices[k]);
                }
            }
        }
    }

    int q;
    cin >> q;
    rep(i, q) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (dist[u][v] == INF)
            cout << "Impossible" << endl;
        else
            cout << dist[u][v] << ' ' << value[u][v] << endl;
    }
}
