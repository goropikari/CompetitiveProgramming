// https://atcoder.jp/contests/math-and-algorithm/tasks/typical90_am
/*2025年01月18日 16時41分31秒*/
#include <atcoder/all>
using namespace atcoder;
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

vvll graph;
vll depth;

void dfs(int x, int p) {
    depth[x] = 1;
    for (int nx : graph[x]) {
        if (nx == p)
            continue;
        dfs(nx, x);
        depth[x] += depth[nx];
    }
}

void solve() {
    int N;
    cin >> N;
    vll A(N), B(N);
    rep(i, N - 1) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }

    depth = vll(N);
    graph = vvll(N);
    rep(i, N - 1) {
        graph[A[i]].push_back(B[i]);
        graph[B[i]].push_back(A[i]);
    }

    dfs(0, -1);

    ll ans = 0;
    rep(i, N) {
        ll x = depth[i];
        ans += x * (N - x);
    }
    cout << ans << endl;
}
