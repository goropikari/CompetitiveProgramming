/*https://atcoder.jp/contests/abc367/tasks/abc367_c*/
/*2025年01月07日 21時59分59秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <numeric>
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
vll R;
vvll ans;

void dfs(int x, int depth, vll& v) {
    v.push_back(x);
    if (depth == N) {
        ll sum = accumulate(all(v), 0);
        if (sum % K == 0) {
            vll t = v;
            ans.push_back(t);
        }
        v.pop_back();
        return;
    }

    rep2(i, 1, R[depth] + 1) {
        dfs(i, depth + 1, v);
    }
    v.pop_back();
}

void solve() {
    cin >> N >> K;
    R.resize(N);
    rep(i, N) cin >> R[i];

    vll v;
    rep2(i, 1, R[0] + 1) {
        dfs(i, 1, v);
    }
    sort(all(ans));
    for (auto v : ans)
        print(v);
}
