// https://atcoder.jp/contests/typical90/tasks/typical90_l
/*2025年03月28日 20時27分15秒*/
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
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

    int h, w;
    cin >> h >> w;
    int q;
    cin >> q;

    auto sub2id = [&](int i, int j) -> int {
        return i * w + j;
    };

    vvint grid(h, vint(w, 0));
    dsu uf(h * w);

    vint di = {0, 1, 0, -1};
    vint dj = {1, 0, -1, 0};

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int r, c;
            cin >> r >> c;
            r--, c--;
            grid[r][c] = 1;

            rep(d, 4) {
                int ni = r + di[d], nj = c + dj[d];
                if (clamp(ni, 0, h - 1) != ni || clamp(nj, 0, w - 1) != nj)
                    continue;
                if (grid[ni][nj] == 1)
                    uf.merge(sub2id(r, c), sub2id(ni, nj));
            }
        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--, ca--, rb--, cb--;
            yesno(grid[ra][ca] == 1 && grid[rb][cb] == 1 && uf.same(sub2id(ra, ca), sub2id(rb, cb)));
        }
    }
}
