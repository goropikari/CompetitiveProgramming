/*https://atcoder.jp/contests/abc339/tasks/abc339_c*/
/*2024年12月29日 02時20分21秒*/
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
    vll A(N);
    rep(i, N) cin >> A[i];

    // int allzero = 1;
    // rep(i, N) {
    //     if (A[i] != 0)
    //         allzero = 0;
    // }
    // if (allzero) {
    //     cout << 0 << endl;
    //     return;
    // }

    ll ans = INF, ng = -1;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;
        ll t = mid;
        bool ok = true;
        rep(i, N) {
            t -= A[N - i - 1];
            if (t < 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = mid;
        } else {
            ng = mid;
        }
    }
    cout << ans << endl;
}
