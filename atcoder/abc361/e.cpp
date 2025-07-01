// https://atcoder.jp/contests/abc361/tasks/abc361_e
// 2025年06月29日 18時12分11秒
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
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

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
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
    vector<vector<pair<ll, ll>>> graph(N);
    vll C;
    rep(i, N - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        C.push_back(c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vll dist(N);
    auto dfs = [&](auto dfs, int now, int p) -> void {
        for (auto [nx, c] : graph[now]) {
            if (nx == p) continue;
            dist[nx] = dist[now] + c;
            dfs(dfs, nx, now);
        }
    };

    dfs(dfs, 0, -1);
    int s = -1;
    ll d = -1;
    rep(i, N) {
        if (d < dist[i]) {
            d = dist[i];
            s = i;
        }
    }

    rep(i, N) dist[i] = 0;
    dfs(dfs, s, -1);
    d = -1;
    rep(i, N) {
        if (d < dist[i]) {
            d = dist[i];
        }
    }

    ll ans = accumulate(all(C), 0ll);
    ans *= 2;
    ans -= d;
    cout << ans << endl;
}
