// https://atcoder.jp/contests/typical90/tasks/typical90_k
/*2025年03月20日 23時51分16秒*/
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

struct Work {
    ll d, c, s;
};

bool operator<(const Work& a, const Work& b) {
    return a.d < b.d;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Work> ws;
    rep(i, n) {
        ll d, c, s;
        cin >> d >> c >> s;
        ws.emplace_back(d, c, s);
    }
    sort(all(ws));

    ws.insert(ws.begin(), {0, 0, 0});

    // dp[i][j]: i 番目までの仕事をこなした状態での j 日目時点での報酬の最大値
    vvll dp(n + 1, vll(5005, 0));
    rep2(i, 1, n + 1) {
        rep2(j, 1, 5005) {
            // i 番目の仕事をしない
            chmax(dp[i][j], dp[i - 1][j]);

            // i 番目の仕事をする
            if (j <= ws[i].d && j - ws[i].c >= 0) {
                chmax(dp[i][j], dp[i - 1][j - ws[i].c] + ws[i].s);
            }
        }
    }

    ll ans = 0;
    rep(i, 5005) chmax(ans, dp[n][i]);
    cout << ans << endl;
}
