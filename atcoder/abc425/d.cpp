// https://atcoder.jp/contests/abc425/tasks/abc425_d
// 2025年09月27日 21時16分43秒
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

    ll H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    vint di = {0, 1, 0, -1};
    vint dj = {1, 0, -1, 0};

    auto neigh = [&](int i, int j) -> bool {
        int cnt = 0;
        rep(d, 4) {
            ll ni = i + di[d], nj = j + dj[d];

            if (clamp(ni, 0ll, H - 1) != ni || clamp(nj, 0ll, W - 1) != nj) continue;
            if (grid[ni][nj] == '#') cnt++;
        }
        return cnt == 1;
    };

    using P = pair<int, int>;
    deque<P> deq;
    rep(i, H) rep(j, W) {
        if (grid[i][j] == '#') {
            continue;
        }
        if (neigh(i, j)) deq.push_back({i, j});
    }

    while (deq.size()) {
        for (auto [i, j] : deq) {
            grid[i][j] = '#';
        }

        deque<P> deqn;
        for (auto [i, j] : deq) {
            rep(d, 4) {
                ll ni = i + di[d], nj = j + dj[d];
                if (clamp(ni, 0ll, H - 1) != ni || clamp(nj, 0ll, W - 1) != nj) continue;
                if (grid[ni][nj] == '#') continue;
                if (neigh(ni, nj)) deqn.push_back({ni, nj});
            }
        }

        swap(deq, deqn);
    }

    ll ans = 0;
    rep(i, H) rep(j, W) if (grid[i][j] == '#') ans++;
    cout << ans << endl;
}
