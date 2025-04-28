// https://atcoder.jp/contests/abc403/tasks/abc403_d
// 2025年04月27日 21時16分09秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
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
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, D;
    cin >> N >> D;
    vll A(N);
    rep(i, N) cin >> A[i];

    map<ll, ll> cnts;
    for (ll x : A)
        cnts[x]++;

    if (D == 0) {
        cout << N - (ll)cnts.size() << endl;
        return;
    }

    ll mx = *max_element(all(A));
    auto cal = [&](ll mod) -> ll {
        vll B = {0};
        for (int i = mod; i <= mx; i += D) {
            B.push_back(cnts[i]);
        }

        int m = B.size();
        // dp[i][j]: j 番目の要素を捨てる(i=1)/捨てない(i=0)
        vvll dp(2, vll(m, INF));
        dp[0][0] = dp[1][0] = 0;

        rep2(i, 1, m) {
            dp[0][i] = dp[1][i - 1];
            dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]) + B[i];
        }
        return min(dp[0][m - 1], dp[1][m - 1]);
    };

    ll ans = 0;
    rep(i, D) {
        ans += cal(i);
    }
    cout << ans << endl;
}
