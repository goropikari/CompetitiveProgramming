/*https://atcoder.jp/contests/abc219/tasks/abc219_d*/
/*2025年01月09日 08時24分37秒*/
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

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;
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
    int N;
    cin >> N;
    int X, Y;
    cin >> X >> Y;
    vll A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vvll cnts(X + 1, vll(Y + 1, INF));
    cnts[0][0] = 0;

    rep(i, N) {
        for (int k = X; k >= 0; k--) {
            for (int l = Y; l >= 0; l--) {
                int nx = clamp(k + A[i], 0LL, (ll)X);
                int ny = clamp(l + B[i], 0LL, (ll)Y);
                chmin(cnts[nx][ny], cnts[k][l] + 1);
            }
        }
    }

    ll ans = -1;
    if (cnts[X][Y] != INF)
        ans = cnts[X][Y];
    cout << ans << endl;
}
