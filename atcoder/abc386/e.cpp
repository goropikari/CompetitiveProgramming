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
    cin >> N >> K;
    // vll A(N);
    A.resize(N);
    visited.resize(N);
    rep(i, N) cin >> A[i];

    rep(i, N) {
        dfs(i, 1, 0);
    }
    cout << ans << endl;
}
