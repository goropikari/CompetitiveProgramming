// https://atcoder.jp/contests/abc139/tasks/abc139_f
// Wed 28 Jan 2026 10:36:03 PM JST
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

struct Point {
    long long x, y;

    // 上半平面判定
    int _up() const {
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

    double norm() {
        return sqrt((double)this->norm2());
    }

    // ノルム^2
    long long norm2() const {
        return x * x + y * y;
    }

    Point operator+(const Point& other) const {
        return Point({x + other.x, y + other.y});
    }

    Point& operator+=(const Point& other) {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    // 偏角ソート用 comparator
    // x 軸正方向から反時計回りに見たときの角度が小さい順
    bool operator<(const Point& other) const {
        int h1 = _up();
        int h2 = other._up();
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<Point> pts;
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) continue;
        pts.emplace_back(x, y);
    }

    sort(all(pts));

    N = pts.size();
    rep(i, N) pts.push_back(pts[i]);

    ll norm_sq = 0;

    rep(i, N) {
        Point now = {0, 0};
        rep(j, N) {
            now += pts[i + j];
            chmax(norm_sq, now.norm2());
        }
    }
    printf("%.15lf\n", sqrt((double)norm_sq));
}
