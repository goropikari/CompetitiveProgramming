// https://atcoder.jp/contests/abc401/tasks/abc401_e
// 2025年05月05日 16時20分46秒
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
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

    int N, M;
    cin >> N >> M;
    vvint graph(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dsu uf(N);
    vector<bool> suteru(N);

    ll cnt = 0;
    rep(i, N) {
        for (int nx : graph[i]) {
            if (nx < i) {
                uf.merge(nx, i);
            } else {
                if (suteru[nx])
                    continue;
                suteru[nx] = 1;
                cnt++;
            }
        }

        if (suteru[i])
            cnt--;

        ll ans = cnt;
        if (uf.size(0) != i + 1) {
            ans = -1;
        }
        cout << ans << endl;
    }
}
