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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> grid(N);
    rep(i, N) cin >> grid[i];

    vvint cumsum(N + 1, vint(N + 1));
    rep(i, N) rep(j, N) cumsum[i + 1][j + 1] = grid[i][j] == '#';
    rep(i, N + 1) rep(j, N) cumsum[i][j + 1] += cumsum[i][j];
    rep(i, N) rep(j, N + 1) cumsum[i + 1][j] += cumsum[i][j];

    auto num_sharp = [&](int si, int sj, int ti, int tj) -> ll {
        ll ret = 0;
        ret = cumsum[ti][tj];
        ret -= cumsum[si][tj];
        ret -= cumsum[ti][sj];
        ret += cumsum[si][sj];
        return ret;
    };

    ll ans = 0;
    rep2(sz, 3, N + 1) {
        rep(i, N) {
            rep(j, N) {
                if (i + sz > N || j + sz > N)
                    continue;

                ll outside = num_sharp(i, j, i + sz, j + sz);
                ll inside = num_sharp(i + 1, j + 1, i + sz - 1, j + sz);

                if (inside)
                    continue;

                if (outside == sz * 3 - 2)
                    chmax(ans, sz - 2);
            }
        }
    }

    cout << ans << endl;
}
