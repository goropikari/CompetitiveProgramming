/*https://atcoder.jp/contests/arc177/tasks/arc177_c*/
/*2025年03月22日 12時33分49秒*/
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

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

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

    int n;
    cin >> n;
    vector<vector<char>> B(n, vector<char>(n, '_')), R(n, vector<char>(n, '_'));
    rep(i, n) {
        rep(j, n) {
            char c;
            cin >> c;
            if (c == 'R')
                R[i][j] = c;
            else
                B[i][j] = c;
        }
    }

    vint di = {1, 0, -1, 0};
    vint dj = {0, -1, 0, 1};

    auto cal = [&](vector<vector<char>>& grid, int si, int sj, int ti, int tj) -> ll {
        vvll dist(n, vll(n, INF));
        dist[si][sj] = 0;

        using P = tuple<int, int, int>;
        priority_queue<P, vector<P>, greater<P>> que;
        que.push({0, si, sj});

        while (que.size()) {
            auto [cost, i, j] = que.top();
            que.pop();

            if (dist[i][j] < cost)
                continue;

            rep(d, 4) {
                int ni = i + di[d], nj = j + dj[d];
                if (clamp(ni, 0, n - 1) != ni || clamp(nj, 0, n - 1) != nj)
                    continue;
                if (grid[ni][nj] == '_') {
                    if (dist[ni][nj] <= dist[i][j] + 1)
                        continue;
                    dist[ni][nj] = dist[i][j] + 1;
                } else {
                    if (dist[ni][nj] <= dist[i][j])
                        continue;
                    dist[ni][nj] = dist[i][j];
                }
                que.push({dist[ni][nj], ni, nj});
            }
        }

        return dist[ti][tj];
    };

    ll ans = cal(R, 0, 0, n - 1, n - 1) + cal(B, 0, n - 1, n - 1, 0);
    cout << ans << endl;
}
