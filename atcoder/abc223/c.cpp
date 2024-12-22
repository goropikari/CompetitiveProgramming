/*https://atcoder.jp/contests/abc223/tasks/abc223_c*/
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

struct Seg {
    double rem;
    double speed;
};

void solve() {
    int N;
    cin >> N;

    deque<Seg> segs;
    rep(i, N) {
        double a, b;
        cin >> a >> b;
        segs.push_back({a, b});
    }

    double ans = 0.0;
    while (segs.size()) {
        if (segs.size() == 1) {
            auto [rem, speed] = segs.front();
            segs.pop_front();
            ans += rem / 2;
            break;
        }

        auto front = segs.front();
        segs.pop_front();
        auto back = segs.back();
        segs.pop_back();
        double tf = front.rem / front.speed;
        double tb = back.rem / back.speed;
        if (tf < tb) {
            ans += front.rem;
            segs.push_back({back.rem - tf * back.speed, back.speed});
        } else {
            double d = tb * front.speed;
            ans += d;
            segs.push_front({front.rem - d, front.speed});
        }
    }
    printf("%.9lf\n", ans);
}

int main() {
    solve();
    return 0;
}
