/*https://atcoder.jp/contests/abc275/tasks/abc275_c*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
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

vector<string> grid(9);

bool isvalid(int x, int y) {
    return clamp(x, 0, 8) == x && clamp(y, 0, 8) == y && grid[x][y] == '#';
}

void solve() {
    rep(i, 9) cin >> grid[i];

    int ans = 0;
    rep(x, 9) {
        rep(y, 9) {
            if (!isvalid(x, y))
                continue;

            rep2(_dx, -8, 9) {
                rep2(_dy, -8, 9) {
                    if (_dx == 0 && _dy == 0)
                        continue;

                    int ok = true;
                    int sx = x, sy = y;
                    int dx = _dx, dy = _dy;
                    rep(i, 4) {
                        int nx = sx + dx, ny = sy + dy;
                        if (!isvalid(nx, ny)) {
                            ok = false;
                            break;
                        };
                        swap(dx, dy);
                        dx *= -1;
                        sx = nx, sy = ny;
                    }
                    if (ok) {
                        // cout << x << ' ' << y << ' ' << dx << ' ' << dy <<
                        // endl;
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans / 4 << endl;
}
