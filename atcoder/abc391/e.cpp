/*https://atcoder.jp/contests/abc391/tasks/abc391_e*/
/*2025年02月01日 22時21分30秒*/
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

ll N;
string A;
vvint cand = {
    {0, 0, 0},
    {0, 0, 1},
    {0, 1, 0},
    {1, 0, 0},
};

map<tuple<ll, ll, ll>, ll> memo;

// [i,j) の範囲の数字を target にするのにかかるコストの最小値
ll dfs(ll i, ll j, int target) {
    if (j - i == 3) {
        vint cnt(2);
        rep2(k, i, j) {
            cnt[A[k] - '0']++;
        }
        if (cnt[target] >= 2)
            return 0;
        else
            return 2 - cnt[target];
    }

    if (memo.count({i, j, target}))
        return memo[{i, j, target}];

    ll ans = INF;
    ll sz = j - i;
    ll diff = sz / 3;
    ll a = i;
    ll b = i + diff;
    ll c = i + 2 * diff;
    // 領域を3分割して最終的に target になる4パターンを
    // 全て試しコストが一番低いものを採用する
    rep(d, 4) {
        ll x1 = dfs(a, b, abs(target - cand[d][0]));
        ll x2 = dfs(b, c, abs(target - cand[d][1]));
        ll x3 = dfs(c, j, abs(target - cand[d][2]));
        chmin(ans, x1 + x2 + x3);
    }
    return memo[{i, j, target}] = ans;
}

void solve() {
    cin >> N >> A;
    ll sz = A.size();

    // target が 0, 1 のどちらかは、何もしなくても達成できるので
    // コストが0になる。
    // コストが nonzero のほうが今回求めたい答え
    ll a = dfs(0, sz, 0);
    ll b = dfs(0, sz, 1);
    cout << max(a, b) << endl;
}
