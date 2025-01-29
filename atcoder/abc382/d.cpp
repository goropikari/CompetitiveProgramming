/*https://atcoder.jp/contests/abc382/tasks/abc382_d*/
/*2025年01月29日 03時14分44秒*/
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

ll N, M;

vvll ans;

void dfs(vll& v) {
    if (v.size() == N) {
        vll w = v;
        ans.push_back(w);
        return;
    }

    int s = v.back();
    for (ll x = s + 1; x <= M - 9 * (N - 1); x++) {
        v.push_back(x);
        dfs(v);
        v.pop_back();
    }
}

void solve() {
    cin >> N >> M;
    for (ll x = 1; x <= M; x++) {
        vll v = {x};
        dfs(v);
    }

    int sz = ans.size();
    rep(i, sz) rep2(j, 1, N) {
        ans[i][j] += j * 9;
    }

    cout << ans.size() << endl;
    for (auto& v : ans)
        print(v);
}
