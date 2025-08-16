// https://atcoder.jp/contests/abc417/tasks/abc417_e
// 2025年08月02日 21時35分59秒
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

// ceil(a/b)
ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

// floor(a/b)
ll floor(ll a, ll b) {
    return a / b;
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto cal = [&]() -> void {
        ll N, M, X, Y;
        cin >> N >> M >> X >> Y;
        X--, Y--;
        vvint graph(N);
        rep(i, M) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (auto& v : graph) sort(all(v));

        vector<bool> used(N);
        vint ans;

        auto dfs = [&](auto dfs, int now, vint& track) -> void {
            if (ans.size()) return;
            track.push_back(now);
            used[now] = true;

            if (now == Y) {
                ans = track;
                return;
            }

            for (int nx : graph[now]) {
                if (used[nx]) continue;
                dfs(dfs, nx, track);
            }
            track.pop_back();
        };

        vint v;
        dfs(dfs, (int)X, v);

        for (int& x : ans) x++;
        print(ans);
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
