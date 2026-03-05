// https://atcoder.jp/contests/abc447/tasks/abc447_f
// Sun 01 Mar 2026 11:10:51 PM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define pb push_back
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

template <typename T>
void chmin(T& a, T b) { a = min(a, b); }
template <typename T>
void chmax(T& a, T b) { a = max(a, b); }

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

template <typename T>
void vprint(vector<T> v) {
    for (auto x : v) cout << x << '\n';
}

void yesno(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

void Yes() { yesno(true); }

void No() { yesno(false); }

// ceil(a/b)
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

// floor(a/b)
ll floor(ll a, ll b) { return a / b; }

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto cal = []() -> void {
        int N;
        cin >> N;
        vvint graph(N);
        rep(i, N - 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;

            graph[a].pb(b);
            graph[b].pb(a);
        }

        ll ans = 1;
        auto dfs = [&](auto dfs, int now, int p = -1) -> ll {
            ll deg = graph[now].size();
            ll mx = 0;
            for (ll nx : graph[now]) {
                if (nx == p) continue;
                ll r = dfs(dfs, nx, now);
                if (deg >= 4) chmax(ans, mx + r + 1);
                if (deg >= 3) chmax(ans, r + 1);
                chmax(mx, r);
            }
            if (deg >= 4) return mx + 1;
            if (deg == 3) return 1;
            return 0;
        };

        dfs(dfs, 0);
        cout << ans << endl;
    };

    int q;
    cin >> q;
    rep(i, q) cal();
}
