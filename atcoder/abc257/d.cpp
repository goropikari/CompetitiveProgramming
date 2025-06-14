// https://atcoder.jp/contests/abc257/tasks/abc257_d
// 2025年06月13日 16時08分10秒
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

const ll INF = (ll)2e18 + 9;
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

    vector<tuple<ll, ll, ll>> nodes;
    rep(i, N) {
        ll x, y, P;
        cin >> x >> y >> P;
        nodes.emplace_back(x, y, P);
    }

    auto f = [&](ll x) -> bool {
        rep(s, N) {
            vector<bool> used(N);
            used[s] = true;
            queue<int> que;
            que.push(s);
            while (que.size()) {
                int now = que.front();
                que.pop();

                rep(nx, N) {
                    if (nx == now) continue;
                    if (used[nx]) continue;
                    auto [xi, yi, pi] = nodes[now];
                    auto [xj, yj, pj] = nodes[nx];
                    if (pi * x >= abs(xi - xj) + abs(yi - yj)) {
                        used[nx] = true;
                        que.push(nx);
                    }
                }
            }

            ll sum = accumulate(all(used), 0);
            if (sum == N) return true;
        }
        return false;
    };

    ll ac = 0;
    rep(i, N) rep(j, N) {
        auto [xi, yi, pi] = nodes[i];
        auto [xj, yj, pj] = nodes[j];
        chmax(ac, abs(xi - xj) + abs(yi - yj));
    }

    ll wa = -1;
    while (ac - wa > 1) {
        ll wj = (ac + wa) / 2;
        if (f(wj))
            ac = wj;
        else
            wa = wj;
    }
    cout << ac << endl;
}
