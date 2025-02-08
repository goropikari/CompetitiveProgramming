/*https://atcoder.jp/contests/abc336/tasks/abc336_d*/
/*2025年02月04日 02時14分09秒*/
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
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    A.push_back(0);
    A.insert(A.begin(), 0);

    N += 2;
    vll dl(N, 0), dr(N, 0);
    rep2(i, 1, N) {
        dl[i] = min(dl[i - 1] + 1, A[i]);
    }

    rep(i, N - 1) {
        int k = N - 1 - i;
        dr[k - 1] = min(dr[k] + 1, A[k - 1]);
    }

    ll ans = 0;
    rep(i, N) {
        chmax(ans, min(dr[i], dl[i]));
    }
    cout << ans << endl;
}
