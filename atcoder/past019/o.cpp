// https://atcoder.jp/contests/past19-open/tasks/past19_o
// 2025年04月22日 10時19分11秒
#include <bits/stdc++.h>
#include <queue>
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

    int n = 4;
    vector S(n, vint(n)), T(n, vint(n));
    rep(i, n) rep(j, n) cin >> S[i][j];
    rep(i, n) rep(j, n) cin >> T[i][j];

    map<vvint, int> dists, dists2;
    dists[S] = 0;
    dists2[T] = 0;

    auto cal = [&](vvint& M, map<vvint, int>& D) -> void {
        vint di = {0, 1, 0, -1};
        vint dj = {1, 0, -1, 0};
        queue<tuple<int, vvint, int, int>> que;
        rep(i, n) rep(j, n) {
            if (M[i][j] == -1)
                que.push({0, M, i, j});
        }

        while (que.size()) {
            auto [dist, X, i, j] = que.front();
            que.pop();

            rep(d, 4) {
                int ni = i + di[d], nj = j + dj[d];
                if (clamp(ni, 0, n - 1) != ni || clamp(nj, 0, n - 1) != nj)
                    continue;

                swap(X[i][j], X[ni][nj]);
                if (!D.count(X)) {
                    D[X] = dist + 1;
                    if (dist + 1 <= 15)
                        que.push({dist + 1, X, ni, nj});
                }
                swap(X[i][j], X[ni][nj]);
            }
        }
    };

    cal(S, dists);
    cal(T, dists2);

    int ans = INF;
    for (auto [v, cnt] : dists) {
        int x;
        if (dists2.count(v) && (x = dists2[v] + cnt) <= 30) {
            chmin(ans, x);
        }
    }
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
}
