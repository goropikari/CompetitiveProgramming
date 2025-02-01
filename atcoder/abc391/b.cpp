/*https://atcoder.jp/contests/abc391/tasks/abc391_b*/
/*2025年02月01日 21時01分56秒*/
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
    int N, M;
    cin >> N >> M;

    vector<string> S(N), T(M);
    rep(i, N) cin >> S[i];
    rep(j, M) cin >> T[j];

    rep(a, N - M + 1) {
        rep(b, N - M + 1) {
            int ok = 1;
            rep(i, M) {
                rep(j, M) {
                    if (S[a + i][b + j] != T[i][j]) {
                        ok = 0;
                    }
                }
            }
            if (ok) {
                cout << a + 1 << ' ' << b + 1 << endl;
                return;
            }
        }
    }
}
