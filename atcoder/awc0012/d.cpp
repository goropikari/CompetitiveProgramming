// https://atcoder.jp/contests/awc0012/tasks/awc0012_d
// Sat 28 Feb 2026 02:53:13 PM JST
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

    ll H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    vvll cnt(H, vll(W, INF));
    cnt[0][0] = 0;

    using P = pair<int, int>;
    deque<P> dq;
    dq.push_back({0, 0});

    vll di = {0, 1, 0, -1};
    vll dj = {1, 0, -1, 0};

    while (dq.size()) {
        auto [i, j] = dq.front();
        dq.pop_front();

        rep(d, 4) {
            ll ni = i + di[d], nj = j + dj[d];
            if (clamp(ni, 0ll, H - 1) != ni || clamp(nj, 0ll, W - 1) != nj) continue;
            if (grid[ni][nj] == '.') {
                if (cnt[ni][nj] > cnt[i][j]) {
                    cnt[ni][nj] = cnt[i][j];
                    dq.push_front({ni, nj});
                }
            } else {
                if (cnt[ni][nj] > cnt[i][j] + 1) {
                    cnt[ni][nj] = cnt[i][j] + 1;
                    dq.push_back({ni, nj});
                }
            }
        }
    }

    cout << cnt[H - 1][W - 1] << endl;
}
