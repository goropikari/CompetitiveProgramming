// https://atcoder.jp/contests/math-and-algorithm/tasks/abc167_d
/*2025年01月13日 17時51分56秒*/
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
    ll N, K;
    cin >> N >> K;

    vll A(N);
    rep(i, N) {
        cin >> A[i];
        A[i]--;
    }

    int mx = 61;
    vvll d(mx, vll(N, 0));
    rep(i, N) d[0][i] = A[i];

    rep2(i, 1, mx) {
        rep(j, N) {
            d[i][j] = d[i - 1][d[i - 1][j]];
        }
    }

    int now = 0;
    rep(i, mx) {
        if (K & 1) {
            now = d[i][now];
        }
        K >>= 1LL;
    }
    cout << now + 1 << endl;
}
