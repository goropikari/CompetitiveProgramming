// https://atcoder.jp/contests/arc121/tasks/arc121_b
// 2025年05月14日 19時34分48秒
#include <bits/stdc++.h>
#include <algorithm>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
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

    int N;
    cin >> N;
    N *= 2;
    vector<pair<ll, char>> ps;
    rep(i, N) {
        ll a;
        char c;
        cin >> a >> c;
        ps.emplace_back(a, c);
    }

    int numr = 0, numg = 0, numb = 0;
    vll R, G, B;
    for (auto [a, c] : ps) {
        if (c == 'R') {
            numr++;
            R.push_back(a);
        }
        if (c == 'G') {
            numg++;
            G.push_back(a);
        }
        if (c == 'B') {
            numb++;
            B.push_back(a);
        }
    }
    if (numr % 2 == 0 && numg % 2 == 0 && numb % 2 == 0) {
        cout << 0 << endl;
        return;
    }

    // B の個数が偶数となるように編集
    if (numr % 2 == 0) {
        swap(numr, numb);
        swap(R, B);
    }
    if (numg % 2 == 0) {
        swap(numg, numb);
        swap(G, B);
    }

    sort(all(R));
    sort(all(G));

    auto closest = [](vll& v, ll x) -> ll {
        ll ans = INF;
        auto it = lower_bound(all(v), x);
        if (it != v.end())
            chmin(ans, abs(x - *it));
        if (it != v.begin()) {
            chmin(ans, abs(x - *prev(it)));
        }
        return ans;
    };

    ll ans = INF;
    // R, G 間で 1 pair 作ったときの最小値
    for (ll x : R) {
        chmin(ans, closest(G, x));
    }
    if ((int)B.size() == 0) {
        cout << ans << endl;
        return;
    }

    // (R, B), (G, B) で 2  pair 作ったときの最小値
    int m = B.size();
    vll r(m), g(m);
    rep(i, m) {
        ll x = B[i];
        r[i] = closest(R, x);
        g[i] = closest(G, x);
    }

    // dp[i][state]: 青を i 番目まで見て、
    // state=1 赤とペアを組む青が決まっている
    // state=2 緑とペアを組む青が決まっている
    // state=3 赤と緑とペアを組む青が決まっている
    vvll dp(m, vll(4, INF));
    dp[0][1] = r[0];
    dp[0][2] = g[0];
    rep2(i, 1, m) {
        dp[i][1] = min(dp[i - 1][1], r[i]);
        dp[i][2] = min(dp[i - 1][2], g[i]);
        dp[i][3] = min(r[i] + dp[i - 1][2], g[i] + dp[i - 1][1]);
        chmin(dp[i][3], dp[i - 1][3]);
    }
    chmin(ans, dp[m - 1][3]);
    cout << ans << endl;
}
