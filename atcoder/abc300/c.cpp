/*https://atcoder.jp/contests/abc300/tasks/abc300_c*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <iostream>
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

int di[] = {1, 1, -1, -1};
int dj[] = {-1, 1, 1, -1};

int search(vector<string>& grid, int i, int j) {
    int sz = INF;
    rep(d, 4) {
        int cnt = 0;
        int x = i, y = j;
        while (grid[x][y] == '#') {
            cnt++;
            x += di[d];
            y += dj[d];
        }
        cnt -= 1;
        chmin(sz, cnt);
    }

    return sz;
}

void solve() {
    int H, W;
    cin >> H >> W;

    vector<string> grid;
    string em = "";
    rep(i, W + 2) em.push_back('.');
    grid.push_back(em);
    rep(i, H) {
        string s;
        cin >> s;
        grid.push_back("." + s + ".");
    }
    grid.push_back(em);

    int n = min(H, W);
    vint ans(n + 1, 0);
    rep2(i, 1, H + 1) {
        rep2(j, 1, W + 1) {
            if (grid[i][j] == '#') {
                int sz = search(grid, i, j);
                ans[sz]++;
            }
        }
    }

    rep2(i, 1, ans.size()) {
        if (i != 1)
            cout << ' ';
        cout << ans[i];
    }
    cout << endl;
}
