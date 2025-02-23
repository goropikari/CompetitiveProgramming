/*https://atcoder.jp/contests/abc363/tasks/abc363_d*/
/*2025年02月23日 20時32分54秒*/
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
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    vll tenth(18, 0);
    tenth[0] = 1;
    rep2(i, 1, 19) tenth[i] = tenth[i - 1] * 10;

    n--;
    for (ll d = 1;; d++) {
        if (n > 9 * tenth[(d - 1) / 2]) {
            n -= 9 * tenth[(d - 1) / 2];
            continue;
        }
        ll b = tenth[(d - 1) / 2] + n - 1;
        string ans = to_string(b);
        ans.resize(d);
        rep(i, d / 2) {
            ans[d - 1 - i] = ans[i];
        }
        cout << ans << endl;
        return;
    }
}
