// https://atcoder.jp/contests/arc164/tasks/arc164_b
// 2025年05月01日 23時53分07秒
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

    vector<pair<int, int>> es;

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        es.emplace_back(a, b);
    }

    vint col(N);
    rep(i, N) cin >> col[i];

    vector<pair<int, int>> same_col;

    dsu uf(N);
    for (auto [u, v] : es) {
        if (col[u] != col[v])
            uf.merge(u, v);
        else
            same_col.push_back({u, v});
    }

    int ok = 0;
    for (auto [u, v] : same_col) {
        if (uf.same(u, v))
            ok = 1;
    }
    yesno(ok);
}
