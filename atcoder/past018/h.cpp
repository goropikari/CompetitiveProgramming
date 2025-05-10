// https://atcoder.jp/contests/past18-open/tasks/past18_h
// 2025年04月17日 00時54分39秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

template <typename T>
struct Cumsum2d {
    vector<vector<T>> data;

    Cumsum2d(vector<vector<T>> v) {
        assert(v.size() != 0);
        assert(v[0].size() != 0);
        int h = v.size();
        int w = v[0].size();

        data = vector<vector<T>>(h + 1, vector<T>(w + 1));

        rep(i, h) rep(j, w) {
            data[i + 1][j + 1] += data[i][j + 1] + data[i + 1][j] - data[i][j] + v[i][j];
        }
    }

    T sum(int si, int sj, int fi, int fj) {
        T ret = data[fi][fj];
        ret -= data[si][fj];
        ret -= data[fi][sj];
        ret += data[si][sj];
        return ret;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector grid(N, vll(N));
    rep(i, N) rep(j, N) {
        char c;
        cin >> c;
        if (c == '#')
            grid[i][j] = 1;
    }

    Cumsum2d cumsum(grid);
    ll ans = 0;
    rep2(k, 1, N) rep(i, N - (k + 2) + 1) rep(j, N - (k + 2) + 1) {
        ll outside = cumsum.sum(i, j, i + k + 2, j + k + 2);
        ll inside = cumsum.sum(i + 1, j + 1, i + k + 1, j + k + 2);
        if (inside)
            continue;
        if (outside == k * 3 + 4)
            chmax(ans, k);
    }
    cout << ans << endl;
}
