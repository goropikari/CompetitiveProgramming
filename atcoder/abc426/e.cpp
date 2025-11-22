// https://atcoder.jp/contests/abc426/tasks/abc426_e
// Sat Oct  4 21:47:42 2025
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

    auto cal_dist = [](ll x1, ll x2, ll y1, ll y2) -> double {
        double dx = x1 - x2, dy = y1 - y2;
        return sqrtl(dx * dx + dy * dy);
    };

    auto cal = [&]() -> void {
        ll tsx, tsy, tgx, tgy;
        ll asx, asy, agx, agy;
        cin >> tsx >> tsy >> tgx >> tgy;
        cin >> asx >> asy >> agx >> agy;

        double tdist = cal_dist(tsx, tgx, tsy, tgy);
        double adist = cal_dist(asx, agx, asy, agy);

        auto takahashi_pos = [&](double t) -> pair<double, double> {
            if (t > tdist) return {tgx, tgy};

            double x = tsx + t * (tgx - tsx) / tdist;
            double y = tsy + t * (tgy - tsy) / tdist;
            return {x, y};
        };
        auto aoki_pos = [&](double t) -> pair<double, double> {
            if (t > adist) return {agx, agy};

            double x = asx + t * (agx - asx) / adist;
            double y = asy + t * (agy - asy) / adist;
            return {x, y};
        };

        auto f = [&](double tx, double ax, double ty, double ay) -> double {
            double dx = tx - ax, dy = ty - ay;
            return sqrt(dx * dx + dy * dy);
        };

        auto ternary = [&](double low, double high) -> double {
            int niter = 60;
            rep(_, niter) {
                double c1 = (low * 2 + high) / 3;
                double c2 = (low + high * 2) / 3;

                auto [tx1, ty1] = takahashi_pos(c1);
                auto [ax1, ay1] = aoki_pos(c1);
                auto [tx2, ty2] = takahashi_pos(c2);
                auto [ax2, ay2] = aoki_pos(c2);

                if (f(tx1, ax1, ty1, ay1) >= f(tx2, ax2, ty2, ay2))
                    low = c1;
                else
                    high = c2;
            }
            auto [tx, ty] = takahashi_pos(low);
            auto [ax, ay] = aoki_pos(low);
            return f(tx, ax, ty, ay);
        };

        double ans = (double)INF;

        {
            double low = 0, high = min(tdist, adist);
            chmin(ans, ternary(low, high));
        }
        {
            double low = min(tdist, adist), high = max(tdist, adist);
            chmin(ans, ternary(low, high));
        }
        printf("%.9lf\n", ans);
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
