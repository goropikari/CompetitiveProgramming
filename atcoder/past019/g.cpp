// https://atcoder.jp/contests/past19-open/tasks/past19_g
// 2025年03月30日 18時02分26秒
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
    vvint A(N + 1, vint(N + 1));
    rep2(i, 1, N + 1) rep2(j, 1, N + 1) {
        cin >> A[i][j];
    }

    int ok = 1;
    rep2(i, 1, N + 1) rep2(j, 1, N + 1) rep2(k, 1, N + 1) {
        if (A[i][j] == 0 || A[j][k] == 0)
            continue;
        int x = A[i][j], y = A[j][k];
        if (A[x][k] == 0 || A[i][y] == 0)
            continue;
        if (A[x][k] != A[i][y])
            ok = 0;
    }

    if (!ok) {
        cout << 0 << endl;
        return;
    }

    int r = 0, c = 0;
    rep2(i, 1, N + 1) rep2(j, 1, N + 1) {
        if (A[i][j] == 0) {
            r = i, c = j;
        }
    }

    int ans = 0;
    rep2(i, 1, N + 1) {
        A[r][c] = i;

        int ok = 1;
        rep2(k, 1, N + 1) {
            int x = A[r][c];
            int y = A[c][k];
            if (A[x][k] != A[r][y])
                ok = 0;
        }

        rep2(k, 1, N + 1) {
            int x = A[k][r];
            int y = A[r][c];
            if (A[x][c] != A[k][y])
                ok = 0;
        }
        if (ok)
            ans++;
    }
    cout << ans << endl;
}
