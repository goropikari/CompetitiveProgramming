/*https://atcoder.jp/contests/abc318/tasks/abc318_d*/
/*2025年01月31日 01時23分24秒*/
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

ll N, m;
vvll D(16, vll(16, 0));
ll ans = 0;

void dfs(int state, int depth, ll sum) {
    if (depth == (N + 1) / 2) {
        chmax(ans, sum);
    }

    int l = 0;
    rep(i, m) if (!(state & (1 << i))) {
        l = i;
        state ^= (1 << i);
        break;
    }

    rep2(i, l + 1, m) {
        if (!(state & (1 << i))) {
            state ^= (1 << i);
            dfs(state, depth + 1, sum + D[l][i]);
            state ^= (1 << i);
        }
    }
}

void solve() {
    cin >> N;

    m = N + N % 2;
    rep(i, N) {
        rep2(j, i + 1, N) {
            cin >> D[i][j];
        }
    }

    dfs(0, 0, 0);

    cout << ans << endl;
}
