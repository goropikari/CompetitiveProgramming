/*https://atcoder.jp/contests/abc280/tasks/abc280_d*/
/*2025年02月23日 17時19分13秒*/
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

void solve() {
    ll k;
    cin >> k;

    vector<pair<ll, ll>> facs;
    {
        ll t = k;
        for (ll i = 2; i * i <= k; i++) {
            if (t % i != 0)
                continue;
            ll cnt = 0;
            while (t % i == 0) {
                cnt++;
                t /= i;
            }
            facs.push_back({i, cnt});
        }
        if (t != 1) {
            facs.push_back({t, 1});
        }
    }

    ll ac = k, wa = 1;
    while (abs(ac - wa) > 1) {
        ll wj = (ac + wa) / 2;
        int ok = 1;
        for (auto [x, cnt] : facs) {
            ll r = 0;
            ll t = wj;
            while (t / x) {
                r += t / x;
                t /= x;
            }
            if (r < cnt)
                ok = 0;
        }
        if (ok)
            ac = wj;
        else
            wa = wj;
    }
    cout << ac << endl;
}
