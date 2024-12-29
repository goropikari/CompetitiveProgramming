/*https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_ae*/
/*2024年12月26日 23時52分41秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<ll,ll>;
using P = pair<int, int>;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;
// const ll MOD = (ll)1e9+9;
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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

struct Point {
    ll x, y;

    Point(ll x, ll y) : x(x), y(y) {}

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    Point operator*(long long int scalar) const {
        return Point(x * scalar, y * scalar);
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

void solve() {
    ll ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    Point A = {ax, ay};
    Point B = {bx, by};
    Point C = {cx, cy};

    Point BC = C - B;
    Point BA = A - B;
    Point CB = B - C;
    Point CA = A - C;

    int pattern = 3;
    if (BA.x * BC.x + BA.y * BC.y < 0)
        pattern = 1;
    if (CB.x * CA.x + CB.y * CA.y < 0)
        pattern = 2;

    if (pattern == 1) {
        printf("%.10lf\n", sqrt(BA.x * BA.x + BA.y * BA.y));
    } else if (pattern == 2) {
        printf("%.10lf\n", sqrt(CA.x * CA.x + CA.y * CA.y));
    } else {
        double d = sqrt(BC.x * BC.x + BC.y * BC.y);
        double area = abs(BA.x * BC.y - BA.y * BC.x);
        printf("%.10lf\n", area / d);
    }
}
