/*https://atcoder.jp/contests/abc346/tasks/abc346_d*/
/*2025年02月10日 00時41分26秒*/
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
    int n;
    string s;
    cin >> n >> s;
    vll c(n), c01(n + 1, 0), c10(n + 1, 0);
    rep(i, n) cin >> c[i];

    rep(i, n) {
        if (s[i] == '0') {
            if (i % 2 == 0) {
                c10[i + 1] = c[i];
            } else {
                c01[i + 1] = c[i];
            }
        } else {
            if (i % 2 == 0) {
                c01[i + 1] = c[i];
            } else {
                c10[i + 1] = c[i];
            }
        }
    }
    rep(i, n) {
        c01[i + 1] += c01[i];
        c10[i + 1] += c10[i];
    }
    // print(c01);
    // print(c10);

    ll ans = INF;
    rep2(i, 1, n) {
        chmin(ans, c01[i] + c10[n] - c10[i]);
        chmin(ans, c10[i] + c01[n] - c01[i]);
    }
    cout << ans << endl;
}
