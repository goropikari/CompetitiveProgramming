/*https://atcoder.jp/contests/abc325/tasks/abc325_c*/
/*2024年12月26日 01時23分49秒*/
#include <atcoder/all>
using namespace atcoder;
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
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    dsu uf(H * W + 1);
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '.') {
                uf.merge(i * W + j, H * W);
                continue;
            }

            rep2(dx, -1, 2) {
                rep2(dy, -1, 2) {
                    int nx = clamp(i + dx, 0, H - 1),
                        ny = clamp(j + dy, 0, W - 1);
                    if (S[nx][ny] == '#')
                        uf.merge(i * W + j, nx * W + ny);
                }
            }
        }
    }

    cout << uf.groups().size() - 1 << endl;
}
