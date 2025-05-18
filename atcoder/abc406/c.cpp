// https://atcoder.jp/contests/abc406/tasks/abc406_c
// 2025年05月17日 21時08分57秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using namespace std;
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
    vll P(N);
    rep(i, N) cin >> P[i];

    int s = -1;
    rep(i, N - 1) {
        if (P[i] < P[i + 1]) {
            s = i;
            break;
        }
    }
    if (s < 0) {
        cout << 0 << endl;
        return;
    }

    vll ids;
    ids.push_back(s);
    rep2(i, s + 1, N) {
        if (i - 1 >= 0 && i + 1 < N) {
            if (P[i - 1] < P[i] && P[i] > P[i + 1])
                ids.push_back(i);
            if (P[i - 1] > P[i] && P[i] < P[i + 1])
                ids.push_back(i);
        }
    }
    if (P[N - 2] < P[N - 1])
        ids.push_back(N - 1);

    ll ans = 0;
    int M = ids.size();
    rep(i, M) {
        if (i % 2 == 1)
            continue;
        if (i + 3 < M) {
            ans += (ids[i + 1] - ids[i]) * (ids[i + 3] - ids[i + 2]);
        }
    }
    cout << ans << endl;
}
