/*https://atcoder.jp/contests/typical90/tasks/typical90_i*/
/*2025年03月19日 21時29分47秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <cmath>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;

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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<ll, ll>> pts;
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        pts.emplace_back(x, y);
    }

    vector<vector<double>> angs(n);

    rep(i, n) {
        auto [sx, sy] = pts[i];
        rep(j, n) {
            if (i == j)
                continue;
            auto [fx, fy] = pts[j];
            ll dx = fx - sx;
            ll dy = fy - sy;
            double d = sqrt(dx * dx + dy * dy);
            double theta = acos(dx / d);
            if (dy < 0) {
                if (dx > 0)
                    theta = M_PI * 2 - theta;
                else
                    theta = M_PI * 2 - theta;
                ;
            }
            angs[i].push_back(theta);
        }
    }

    rep(i, n) sort(all(angs[i]));

    auto calang = [](double a, double b) -> double {
        if (a > b)
            swap(a, b);
        double ans = b - a;
        if (ans > M_PI)
            ans = M_PI * 2 - ans;
        return ans;
    };

    double ans = 0.0;
    rep(i, n) {
        rep(j, n - 1) {
            double o = angs[i][j];
            double target = o + M_PI;
            if (target > M_PI * 2) {
                target -= M_PI * 2;
            }
            auto it = lower_bound(all(angs[i]), target);
            auto dist = it - angs[i].begin();

            int ni = dist % (n - 1);
            int pi = (dist + n - 1 - 1) % (n - 1);
            chmax(ans, calang(o, angs[i][ni]));
            chmax(ans, calang(o, angs[i][pi]));
        }
    }

    printf("%.9lf\n", ans * 180.0 / M_PI);
}
