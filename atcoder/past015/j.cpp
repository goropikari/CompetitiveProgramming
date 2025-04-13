// https://atcoder.jp/contests/past15-open/tasks/past202306_j
// 2025年04月13日 21時42分35秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
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
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

struct Point {
    // 攻撃力、攻撃される回数、空中にいるかどうか
    ll power, cnt, flag;
};

bool operator<(const Point& a, const Point& b) {
    ll aw = a.power, bw = b.power;
    if (a.flag == 1 && a.cnt > 1) {
        aw *= 2;
    }
    if (b.flag == 1 && b.cnt > 1) {
        bw *= 2;
    }

    return aw < bw;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    vll a(N), b(N), x(N);
    rep(i, N) {
        cin >> a[i] >> b[i] >> x[i];
    }

    priority_queue<Point> pq;
    rep(i, N) {
        if (x[i] == 1)
            pq.push({a[i], b[i], x[i]});
        else if (b[i] - 1 > 0)
            pq.push({a[i], b[i] - 1, x[i]});
    }

    while (pq.size() && M) {
        auto [p, h, f] = pq.top();
        pq.pop();
        if (f == 1) {
            M--;
            f = 0;
            h -= 2;
            if (h > 0)
                pq.push({p, h, f});
        } else {
            ll m = min(M, h);
            h -= m;
            M -= m;
            if (h > 0)
                pq.push({p, h, f});
        }
    }

    ll ans = 0;
    while (pq.size()) {
        auto [p, h, _] = pq.top();
        pq.pop();
        ans += p * h;
    }
    cout << ans << endl;
}
