// https://atcoder.jp/contests/abc433/tasks/abc433_e
// Sat 22 Nov 2025 09:54:37 PM JST
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
        ll N, M;
        cin >> N >> M;

        vll X(N), Y(M);
        rep(i, N) cin >> X[i];
        rep(i, M) cin >> Y[i];

        ll mat_sz = N * M;

        vvll upper_grid(N, vll(M)), ans(N, vll(M));
        vll kakutei(mat_sz + 1);
        vector<vector<pair<ll, ll>>> cand(mat_sz + 1);
        rep(i, N) rep(j, M) {
            ll mi = min(X[i], Y[j]);
            upper_grid[i][j] = mi;
            if (X[i] == Y[j]) {
                kakutei[X[i]] = 1;
                ans[i][j] = X[i];
            } else {
                cand[mi].push_back({i, j});
            }
        }

        set<ll> appear;
        {
            for (auto x : X) appear.insert(x);
            for (auto x : Y) appear.insert(x);
        }

        for (ll x = mat_sz; x > 0; x--) {
            if (kakutei[x]) continue;
            if (appear.count(x)) {
                for (auto [i, j] : cand[x]) {
                    if (ans[i][j]) continue;
                    ans[i][j] = x;
                    kakutei[x] = 1;
                    break;
                }
            }
        }

        {
            vector<tuple<ll, ll, ll>> tmp;
            rep(i, N) rep(j, M) {
                if (!ans[i][j]) tmp.emplace_back(upper_grid[i][j], i, j);
            }
            sort(all(tmp));

            int now = mat_sz;
            while (now) {
                if (kakutei[now]) {
                    now--;
                    continue;
                }
                if (!tmp.size()) break;
                auto [_, i, j] = tmp.back();
                tmp.pop_back();
                ans[i][j] = now;
                now--;
            }
        }

        auto check = [&](vvll& grid) -> bool {
            vint used(mat_sz + 1);
            vll x(N), y(M);
            rep(i, N) rep(j, M) {
                chmax(x[i], grid[i][j]);
                chmax(y[j], grid[i][j]);
                used[grid[i][j]] = 1;
            }

            ll sum = accumulate(all(used), 0);

            return x == X && y == Y && sum == N * M;
        };

        if (check(ans)) {
            Yes();
            for (auto v : ans) print(v);
        } else {
            No();
        }
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
