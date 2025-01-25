/*https://atcoder.jp/contests/abc335/tasks/abc335_d*/
/*2025年01月24日 21時50分33秒*/
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

void solve() {
    int N;
    cin >> N;

    vvint grid(N, vint(N, -1));
    grid[N / 2][N / 2] = 0;

    map<char, pair<int, int>> mp = {
        {'U', {-1, 0}},
        {'D', {1, 0}},
        {'R', {0, 1}},
        {'L', {0, -1}},
    };

    map<char, char> nxd = {
        {'U', 'R'},
        {'D', 'L'},
        {'R', 'D'},
        {'L', 'U'},
    };

    queue<pair<int, int>> que;
    que.push({0, 0});
    char prev = 'U';
    int cnt = 0;
    while (que.size()) {
        auto [i, j] = que.front();
        que.pop();
        cnt++;
        grid[i][j] = cnt;
        if (cnt == N * N - 1)
            break;

        int ni, nj;
        while (true) {
            auto [di, dj] = mp[prev];
            ni = i + di, nj = j + dj;
            if (clamp(ni, 0, N - 1) != ni || clamp(nj, 0, N - 1) != nj ||
                grid[ni][nj] != -1) {
                prev = nxd[prev];
            } else {
                que.push({ni, nj});
                break;
            }
        }
    }

    rep(i, N) {
        rep(j, N) {
            if (j != 0)
                cout << ' ';
            if (i == N / 2 && j == N / 2) {
                cout << "T";
            } else
                cout << grid[i][j];
        }
        cout << endl;
    }
}
