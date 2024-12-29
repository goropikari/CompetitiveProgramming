/*https://atcoder.jp/contests/abc327/tasks/abc327_c*/
/*2024年12月26日 20時27分21秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
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

void solve() {
    int n = 9;
    vvint grid(n, vint(n));
    rep(i, n) rep(j, n) cin >> grid[i][j];

    rep(i, n) {
        set<int> s;
        rep(j, n) {
            s.insert(grid[i][j]);
        }
        if (s.size() != n) {
            yesno(false);
            return;
        }
    }
    rep(j, n) {
        set<int> s;
        rep(i, n) {
            s.insert(grid[i][j]);
        }
        if (s.size() != n) {
            yesno(false);
            return;
        }
    }

    for (int i = 0; i < n; i += 3) {
        for (int j = 0; j < n; j += 3) {
            set<int> s;
            rep(x, 3) {
                rep(y, 3) {
                    s.insert(grid[i + x][j + y]);
                }
            }
            if (s.size() != n) {
                yesno(false);
                return;
            }
        }
    }
    yesno(true);
}
