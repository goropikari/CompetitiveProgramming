/*https://atcoder.jp/contests/abc369/tasks/abc369_c*/
/*2025年01月07日 23時21分47秒*/
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
    vll A(N);
    rep(i, N) cin >> A[i];

    vll diff;
    rep(i, N - 1) diff.push_back(A[i + 1] - A[i]);
    ll prev = -INF;
    vll shrink;
    int cnt = 0;
    diff.push_back(INF);
    rep(i, diff.size()) {
        if (diff[i] == prev)
            cnt++;
        else {
            shrink.push_back(cnt);
            cnt = 1;
        }
        prev = diff[i];
    }

    ll ans = 0;
    rep2(i, 1, shrink.size()) {
        ll t = shrink[i] + 1;
        ans += t * (t - 1) / 2;
    }
    ans += N;
    cout << ans << endl;
}
