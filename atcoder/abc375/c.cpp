/*https://atcoder.jp/contests/abc375/tasks/abc375_c*/
/*2025年01月08日 20時14分39秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
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

void solve() {
    ll N;
    cin >> N;
    vector<vector<char>> A(N + 1, vector<char>(N + 1)), B;
    rep(i, N) rep(j, N) cin >> A[i + 1][j + 1];
    B = A;
    for (int i = 1; i <= N / 2; i++) {
        if (i % 4 == 1) {
            for (int x = i; x <= N + 1 - i; x++) {
                int ymin = i, ymax = N + 1 - i;
                B[ymin][N + 1 - x] = A[x][ymin];
                B[ymax][N + 1 - x] = A[x][ymax];
            }
            for (int y = i; y <= N + 1 - i; y++) {
                int xmin = i, xmax = N + 1 - i;
                B[y][N + 1 - xmin] = A[xmin][y];
                B[y][N + 1 - xmax] = A[xmax][y];
            }
        } else if (i % 4 == 2) {
            for (int x = i; x <= N + 1 - i; x++) {
                int ymin = i, ymax = N + 1 - i;
                B[N + 1 - x][N + 1 - ymin] = A[x][ymin];
                B[N + 1 - x][N + 1 - ymax] = A[x][ymax];
            }
            for (int y = i; y <= N + 1 - i; y++) {
                int xmin = i, xmax = N + 1 - i;
                B[N + 1 - xmin][N + 1 - y] = A[xmin][y];
                B[N + 1 - xmax][N + 1 - y] = A[xmax][y];
            }
        } else if (i % 4 == 3) {
            for (int x = i; x <= N + 1 - i; x++) {
                int ymin = i, ymax = N + 1 - i;
                B[N + 1 - ymin][x] = A[x][ymin];
                B[N + 1 - ymax][x] = A[x][ymax];
            }
            for (int y = i; y <= N + 1 - i; y++) {
                int xmin = i, xmax = N + 1 - i;
                B[N + 1 - y][xmin] = A[xmin][y];
                B[N + 1 - y][xmax] = A[xmax][y];
            }
        }
        A = B;
    }

    rep(i, N) {
        rep(j, N) cout << A[i + 1][j + 1];
        cout << endl;
    }
}