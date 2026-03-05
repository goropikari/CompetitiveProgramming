// https://atcoder.jp/contests/abc311/tasks/abc311_d
// Thu 05 Mar 2026 09:47:32 PM JST
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
bool chmin(T& a, T b) {
    bool change = a > b;
    a = min(a, b);
    return change;
}
template <typename T>
bool chmax(T& a, T b) {
    bool change = a < b;
    a = max(a, b);
    return change;
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

    ll N, M;
    cin >> N >> M;
    vector<string> grid(N);
    rep(i, N) cin >> grid[i];

    vvint visited(N, vint(M));
    vint di = {0, 1, 0, -1};
    vint dj = {1, 0, -1, 0};

    auto dfs = [&](auto dfs, int i, int j) -> void {
        visited[i][j] = 1;
        rep(d, 4) {
            int ii = i, jj = j;
            while (grid[ii + di[d]][jj + dj[d]] != '#') {
                visited[ii][jj] = 1;
                ii += di[d], jj += dj[d];
            }
            if (!visited[ii][jj]) dfs(dfs, ii, jj);
        }
    };

    dfs(dfs, 1, 1);

    ll ans = 0;
    rep(i, N) rep(j, M) ans += visited[i][j];
    cout << ans << endl;
}
