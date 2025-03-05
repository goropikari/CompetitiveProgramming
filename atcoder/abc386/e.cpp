/*https://atcoder.jp/contests/abc386/tasks/abc386_e*/
/*2024年12月28日 22時06分17秒*/
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

ll N, K;
vll A, visited;
ll ans = 0;

void dfs(int now, int cnt, ll sum) {
    sum = sum ^ A[now];
    visited[now] = 1;

    if (cnt == K) {
        chmax(ans, sum);
        visited[now] = 0;
        return;
    }

    rep2(i, now + 1, N) {
        if (visited[i])
            continue;
        dfs(i, cnt + 1, sum);
    }
    visited[now] = 0;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vll a(n);
    rep(i, n) cin >> a[i];

    bool flip = false;
    if (k > n / 2) {
        flip = true;
        k = n - k;
    }
    ll tot = accumulate(all(a), 0ll, [&](ll acc, ll x) -> ll {
        return acc ^ x;
    });

    ll ans = 0;
    auto dfs = [&](auto dfs, int cnt, int depth, ll sum) {
        if (cnt == k) {
            if (flip) {
                chmax(ans, tot ^ sum);
            } else {
                chmax(ans, sum);
            }
            return;
        }
        if (depth == n)
            return;
        dfs(dfs, cnt, depth + 1, sum);
        dfs(dfs, cnt + 1, depth + 1, sum ^ a[depth]);
    };

    dfs(dfs, 0, 0, 0);
    cout << ans << '\n';
}
