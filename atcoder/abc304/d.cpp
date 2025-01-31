/*https://atcoder.jp/contests/abc304/tasks/abc304_d*/
/*2025年01月31日 23時10分02秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ll W, H, N;
    cin >> W >> H >> N;

    vll p(N), q(N);
    rep(i, N) {
        cin >> p[i] >> q[i];
    }

    ll na;
    cin >> na;
    vll a(na + 1);
    rep(i, na) {
        cin >> a[i];
    }
    a.back() = W;

    ll nb;
    cin >> nb;
    vll b(nb + 1);
    rep(i, nb) {
        cin >> b[i];
    }
    b.back() = H;

    // イチゴが入るピースの右下の座標
    map<pair<ll, ll>, ll> cnt;
    rep(i, N) {
        ll rh, rw;
        rh = *lower_bound(all(a), p[i]);
        rw = *lower_bound(all(b), q[i]);

        cnt[{rh, rw}]++;
    }

    // ピースの数が最大数より少なかったらイチゴが 0 個のピースを sentinel
    // として一つ追加
    if ((ll)cnt.size() < (na + 1) * (nb + 1))
        cnt[{-1, -1}] = 0;

    ll maxv = 0, minv = INF;
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        chmin(minv, it->second);
        chmax(maxv, it->second);
    }
    cout << minv << ' ' << maxv << endl;
}
