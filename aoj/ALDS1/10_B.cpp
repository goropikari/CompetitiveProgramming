// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_B
/*2025年01月23日 20時14分56秒*/
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

ll N;
vvll dp;
vector<pair<ll, ll>> mats;

ll cal(int l, int r) {
    if (r - l <= 1)
        return 0;
    if (dp[l][r] >= 0)
        return dp[l][r];

    ll ans = INF;
    rep2(k, l + 1, r) {
        chmin(ans, cal(l, k) + cal(k, r) +
                       mats[l].first * mats[k].first * mats[r - 1].second);
    }
    return dp[l][r] = ans;
}

void solve() {
    cin >> N;
    rep(i, N) {
        ll l, r;
        cin >> l >> r;
        mats.push_back({l, r});
    }

    dp = vvll(N + 1, vll(N + 1, -1));

    cout << cal(0, N) << endl;
}
