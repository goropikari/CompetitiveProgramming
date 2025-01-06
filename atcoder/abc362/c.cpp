/*https://atcoder.jp/contests/abc362/tasks/abc362_c*/
/*2025年01月06日 23時51分12秒*/
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
    int N;
    cin >> N;
    vll L(N), R(N);
    rep(i, N) cin >> L[i] >> R[i];
    ll ltot = 0, rtot = 0;
    rep(i, N) {
        ltot += L[i];
        rtot += R[i];
    }

    if (!(ltot <= 0 && 0 <= rtot)) {
        yesno(false);
        return;
    }

    vll ans = L;
    ll tot = ltot;
    rep(i, N) {
        if (tot - L[i] + R[i] < 0) {
            tot = tot - L[i] + R[i];
            ans[i] = R[i];
        } else {  // tot -L[i] + R[i] >= 0
            tot -= L[i];
            ans[i] = -tot;
            tot = 0;
        }
    }
    yesno(true);
    print(ans);
}
