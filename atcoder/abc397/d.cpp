/*https://atcoder.jp/contests/abc397/tasks/abc397_d*/
/*2025年03月15日 21時16分42秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
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

ll sol(ll a, ll b, ll c) {
    ll wa = -1, ac = INF;
    while (abs(ac - wa) > 1) {
        ll wj = (wa + ac) / 2;
        if (a * wj * wj + b * wj + c >= 0) {
            ac = wj;
        } else {
            wa = wj;
        }
    }
    return ac;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    for (ll d = 1; d * d * d < N; d++) {
        if (N % d)
            continue;
        ll y = sol(3, 3 * d, d * d - N / d);
        if (y <= 0)
            continue;
        ll x = d + y;
        if (x * x * x - y * y * y == N) {
            cout << d + y << ' ' << y << endl;
            return;
        }
    }
    cout << -1 << endl;
}
