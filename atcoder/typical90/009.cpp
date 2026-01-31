// https://atcoder.jp/contests/typical90/tasks/typical90_i
// Wed 28 Jan 2026 09:41:39 PM JST
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

struct Point {
    long long x, y;

    // 上半平面判定
    int is_up() const {
        if (y > 0) return 0;
        if (y == 0 && x > 0) return 0;
        return 1;
    }

    // 外積
    long long cross(const Point& other) const {
        return x * other.y - y * other.x;
    }

    // 内積
    long long dot(const Point& other) const {
        return x * other.x + y * other.y;
    }

    // ノルム^2
    long long norm2() const {
        return x * x + y * y;
    }

    // 偏角ソート用 comparator
    bool operator<(const Point& other) const {
        int h1 = is_up();
        int h2 = other.is_up();
        if (h1 != h2) return h1 < h2;
        return cross(other) > 0;
    }

    // ===== 角度計算 =====
    // this と other のなす角（0〜π, ラジアン）
    double angle(const Point& other) const {
        double d = (double)dot(other);
        double n = sqrt((double)norm2() * other.norm2());
        double c = d / n;

        return acos(clamp(c, -1.0, 1.0));
    }

    // 角度（度）
    double angle_deg(const Point& other) const {
        return angle(other) * 180.0 / M_PI;
    }
};

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vll X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    double ans = 0.0;
    rep(j, N) {
        vector<Point> pts;
        rep(i, N) {
            if (i == j) continue;
            pts.emplace_back(X[i] - X[j], Y[i] - Y[j]);
        }
        sort(all(pts));

        ll M = N - 1;
        rep(i, M) pts.push_back(pts[i]);

        ll r = 0;
        rep(l, M) {
            if (r < l) r = l;
            while (r + 1 < l + M && pts[l].cross(pts[r + 1]) >= 0) r++;

            chmax(ans, pts[l].angle_deg(pts[r]));
            if (r + 1 < l + M)
                chmax(ans, pts[l].angle_deg(pts[r + 1]));
        }
    }

    printf("%.9lf\n", ans);
}
