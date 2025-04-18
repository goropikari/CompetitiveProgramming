/*https://atcoder.jp/contests/abc394/tasks/abc394_e*/
/*2025年02月24日 16時40分23秒*/
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
    int n;
    cin >> n;
    vector<string> delta(n);
    rep(i, n) cin >> delta[i];

    vvll dist(n, vll(n, -1));
    queue<pair<int, int>> que;

    rep(i, n) {
        dist[i][i] = 0;
        que.push({i, i});
    }

    rep(i, n) rep(j, n) {
        if (i != j && delta[i][j] != '-') {
            dist[i][j] = 1;
            que.push({i, j});
        }
    }

    while (que.size()) {
        auto [i, j] = que.front();
        que.pop();

        rep(k, n) {
            rep(l, n) {
                if (delta[k][i] != '-' && delta[k][i] == delta[j][l] &&
                    dist[k][l] == -1) {
                    dist[k][l] = dist[i][j] + 2;
                    que.push({k, l});
                }
            }
        }
    }

    for (auto v : dist)
        print(v);
}
