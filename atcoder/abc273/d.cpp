/*https://atcoder.jp/contests/abc273/tasks/abc273_d*/
/*2025年02月22日 01時20分17秒*/
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

struct Grid {
    int h, w;
    int r, c;
    map<int, vint> rows, cols;

    Grid(int h, int w, int r, int c) : h(h), w(w), r(r), c(c) {};

    void add_walls(int n, vint& rs, vint& cs) {
        rep(i, n) {
            rows[rs[i]].push_back(cs[i]);
            cols[cs[i]].push_back(rs[i]);
        }

        for (auto it = rows.begin(); it != rows.end(); it++) {
            (it->second).push_back(0);
            (it->second).push_back(w + 1);
            sort(all(it->second));
        }
        for (auto it = cols.begin(); it != cols.end(); it++) {
            (it->second).push_back(0);
            (it->second).push_back(h + 1);
            sort(all(it->second));
        }
    }

    void move(char dir, int cnt) {
        if (dir == 'R') {
            if (rows[r].size()) {
                auto it = upper_bound(all(rows[r]), c);
                c += min(cnt, *it - c - 1);
            } else {
                c = min(c + cnt, w);
            }
        }
        if (dir == 'D') {
            if (cols[c].size()) {
                auto it = upper_bound(all(cols[c]), r);
                r += min(cnt, *it - r - 1);
            } else {
                r = min(r + cnt, h);
            }
        }
        if (dir == 'L') {
            if (rows[r].size()) {
                auto it = lower_bound(all(rows[r]), c);
                it--;
                c -= min(cnt, c - *it - 1);
            } else {
                c = max(c - cnt, 1);
            }
        }
        if (dir == 'U') {
            if (cols[c].size()) {
                auto it = lower_bound(all(cols[c]), r);
                it--;
                r -= min(cnt, r - *it - 1);
            } else {
                r = max(r - cnt, 1);
            }
        }
    }
};

void solve() {
    int h, w, rs, cs;
    cin >> h >> w >> rs >> cs;
    int n;
    cin >> n;
    vint rows(n), cols(n);
    rep(i, n) cin >> rows[i] >> cols[i];
    int q;
    cin >> q;
    vector<char> dirs(q);
    vint ls(q);
    rep(i, q) {
        cin >> dirs[i] >> ls[i];
    }

    Grid grid(h, w, rs, cs);
    grid.add_walls(n, rows, cols);

    rep(i, q) {
        grid.move(dirs[i], ls[i]);
        cout << grid.r << ' ' << grid.c << endl;
    }
}
