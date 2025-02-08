/*https://atcoder.jp/contests/abc317/tasks/abc317_d*/
/*2025年02月05日 21時53分06秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <tuple>
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
    ll N;
    cin >> N;

    ll tot = 0;
    ll tak = 0;
    vector<tuple<ll, ll, ll>> lose;
    rep(i, N) {
        ll x, y, z;
        cin >> x >> y >> z;
        tot += z;
        if (x > y) {
            tak += z;
        } else {
            lose.emplace_back(x, y, z);
        }
    }

    if (tak > tot / 2) {
        cout << 0 << endl;
        return;
    }

    ll need = (tot + 1) / 2;
    ll rem = need - tak;

    lose.insert(lose.begin(), make_tuple(0, 0, 0));
    int sz = lose.size();

    // dp[i][j]:
    // i 番目までの未勝利地区のうち鞍替えさせて j 議席獲得するのに
    // 必要な最小の鞍替え人数
    vvll dp(sz, vll(tot + 1, INF));
    dp[0][0] = 0;

    rep2(i, 1, sz) {
        auto [x, y, z] = lose[i];
        rep(j, tot + 1) {
            chmin(dp[i][j], dp[i - 1][j]);
            if (j - z >= 0)
                chmin(dp[i][j], dp[i - 1][j - z] + (x + y + 1) / 2 - x);
        }
    }

    ll ans = INF;
    rep2(i, rem, tot + 1) {
        chmin(ans, dp[sz - 1][i]);
    }
    cout << ans << endl;
}
