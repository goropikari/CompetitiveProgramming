/*https://atcoder.jp/contests/abc302/tasks/abc302_d*/
/*2025年01月22日 00時59分11秒*/
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
    ll N, M, D;
    cin >> N >> M >> D;

    vll A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    sort(all(A));
    sort(all(B));

    ll ans = -1;
    rep(i, N) {
        auto it = lower_bound(all(B), A[i] + D + 1);
        if (it == B.begin())
            continue;
        it--;
        if (abs(*it - A[i]) <= D)
            chmax(ans, *it + A[i]);
    }

    rep(i, M) {
        auto it = lower_bound(all(A), B[i] + D + 1);
        if (it == A.begin())
            continue;
        it--;
        if (abs(*it - B[i]) <= D)
            chmax(ans, *it + B[i]);
    }
    cout << ans << endl;
}
