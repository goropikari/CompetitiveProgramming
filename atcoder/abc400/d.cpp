// https://atcoder.jp/contests/abc400/tasks/abc400_d
// 2025年04月05日 21時15分38秒
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

    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    A--, B--, C--, D--;

    vint di = {1, 0, -1, 0};
    vint dj = {0, -1, 0, 1};

    vint graph(H * W);
    // cnt, position
    using P = pair<ll, pair<int, int>>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, {A, B}});
    vvll dist(H, vll(W, INF));
    dist[A][B] = 0;

    while (pq.size()) {
        auto [cost, now] = pq.top();
        pq.pop();
        auto [i, j] = now;

        if (dist[i][j] < cost)
            continue;

        rep(d, 4) {
            int wall = 0;
            for (int k = 1; k <= 2; k++) {
                int ni = i + di[d] * k, nj = j + dj[d] * k;
                if (clamp(ni, 0, H - 1) != ni || clamp(nj, 0, W - 1) != nj)
                    continue;
                wall = wall || grid[ni][nj] == '#';
                ll w = cost + wall;
                if (dist[ni][nj] > w) {
                    dist[ni][nj] = w;
                    pq.push({w, {ni, nj}});
                }
            }
        }
    }

    cout << dist[C][D] << endl;
}
