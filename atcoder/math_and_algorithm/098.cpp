// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_bu
/*2025年01月18日 01時37分57秒*/
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

    Point operator-(const Point& b) {
        return Point({this->x - b.x, this->y - b.y});
    }

    ll cross(const Point& b) { return this->x * b.y - this->y * b.x; }
};

void solve() {
    ll N;
    cin >> N;

    vll X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    ll A, B;
    cin >> A >> B;

    vector<Point> pts(N);
    rep(i, N) pts[i] = {X[i], Y[i]};

    vector<Point> edges(N);
    rep(i, N) {
        edges[i] = pts[(i + 1) % N] - pts[i];
    }

    Point target = {A, B};

    rep(i, N) {
        Point v = target - pts[i];
        if (edges[i].cross(edges[(i + 1) % N]) < 0) {
            if (edges[i].cross(v) >= 0) {
                cout << "OUTSIDE" << endl;
                return;
            }
        } else {
            if (edges[i].cross(v) <= 0) {
                cout << "OUTSIDE" << endl;
                return;
            }
        }
    }

    cout << "INSIDE" << endl;
}
