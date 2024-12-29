/*https://atcoder.jp/contests/abc332/tasks/abc332_c*/
/*2024年12月26日 21時14分51秒*/
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
    int N, M;
    string S;
    cin >> N >> M >> S;

    int ans = 0;
    int max_at_t = 0, max_t = M, used_at = 0, used_t = 0;
    rep(i, N) {
        if (S[i] == '0') {
            used_at = 0;
            used_t = 0;
        } else if (S[i] == '1') {
            if (used_t + 1 <= max_t) {
                used_t++;
            } else if (used_at + 1 <= max_at_t) {
                used_at++;
            } else {
                ans++;
                max_at_t++;
                used_at++;
            }
        } else {
            if (used_at + 1 <= max_at_t) {
                used_at++;
            } else {
                ans++;
                max_at_t++;
                used_at++;
            }
        }
    }
    cout << ans << endl;
}
