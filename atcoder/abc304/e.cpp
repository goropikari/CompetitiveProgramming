/*https://atcoder.jp/contests/abc304/tasks/abc304_e*/
/*2025年03月04日 01時17分12秒*/
#include <atcoder/all>
using namespace atcoder;
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
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> memo;
    dsu uf(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        uf.merge(u, v);
    }

    int k;
    cin >> k;
    rep(i, k) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int lx = uf.leader(x), ly = uf.leader(y);
        if (lx > ly)
            swap(lx, ly);
        memo.insert({lx, ly});
    }

    int q;
    cin >> q;
    rep(i, q) {
        int p, q;
        cin >> p >> q;
        p--, q--;

        int lp = uf.leader(p), lq = uf.leader(q);
        if (lp > lq)
            swap(lp, lq);

        yesno(!memo.count({lp, lq}));
    }
}
