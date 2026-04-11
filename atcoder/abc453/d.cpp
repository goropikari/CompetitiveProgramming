// https://atcoder.jp/contests/abc453/tasks/abc453_d
// Sat 11 Apr 2026 09:13:12 PM JST
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
void print(vector<T> v, char delim = ' ') {
    int n = v.size();
    rep(i, n) {
        if (i == 0)
            cout << v[i];
        else
            cout << delim << v[i];
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

    ll H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    using P = pair<ll, ll>;
    P start, goal;
    rep(i, H) rep(j, W) {
        if (grid[i][j] == 'S') start = {i, j};
        if (grid[i][j] == 'G') goal = {i, j};
    }

    string dir = "UDLR";
    vll di = {-1, 1, 0, 0};
    vll dj = {0, 0, -1, 1};

    ll UP = 5e6;

    // dist[pr][i][j]: 直前の方向が pr で (i, j) に到達したときの移動回数の最小値
    vector dist(vector(4, vector(H, vll(W, INF))));

    ll si = start.first, sj = start.second;
    ll gi = goal.first, gj = goal.second;
    rep(pr, 4) dist[pr][si][sj] = 0;
    grid[si][sj] = grid[gi][gj] = '.';

    queue<tuple<ll, ll, ll>> que;
    rep(pr, 4)
        que.push({pr, si, sj});

    int ok = 0;
    while (que.size()) {
        auto [pr, i, j] = que.front();
        que.pop();

        char nowc = grid[i][j];
        if (dist[pr][i][j] >= UP) continue;
        rep(nx, 4) {
            ll ni = i + di[nx], nj = j + dj[nx];
            if (clamp(ni, 0ll, H - 1) != ni || clamp(nj, 0ll, W - 1) != nj) continue;
            if (grid[ni][nj] == '#') continue;

            if (nowc == '.') {
                // nothing
            } else if (nowc == 'o') {
                if (pr != nx) continue;
            } else if (nowc == 'x') {
                if (pr == nx) continue;
            }
            if (chmin(dist[nx][ni][nj], dist[pr][i][j] + 1)) {
                que.push({nx, ni, nj});
            }

            if (ni == gi && nj == gj) {
                ok = 1;
                break;
            }
        }
        if (ok) break;
    }

    if (!ok) {
        No();
        return;
    }

    ll initdir = -1;
    rep(d, 4) if (dist[d][gi][gj] != INF) {
        initdir = d;
        break;
    }

    // dir, i, j
    using T = tuple<ll, ll, ll>;
    ll len = dist[initdir][gi][gj];

    ll i = gi, j = gj;
    ll d = initdir;
    vll dans = {d};
    while (len > 1) {
        ll pi = i - di[d], pj = j - dj[d];
        rep(pr, 4) {
            if (dist[pr][pi][pj] != len - 1) continue;

            char pc = grid[pi][pj];
            if (pc == 'o' && pr != d) {
                continue;
            }
            if (pc == 'x' && pr == d) {
                continue;
            }

            dans.pb(pr);
            len--;
            i = pi;
            j = pj;
            d = pr;
            break;
        }
    }
    reverse(all(dans));

    string ans = "";
    for (ll x : dans) ans.pb(dir[x]);

    Yes();
    cout << ans << endl;
}
