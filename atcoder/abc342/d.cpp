/*https://atcoder.jp/contests/abc342/tasks/abc342_d*/
/*2025年02月07日 21時09分40秒*/
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
    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];

    int sz = 2 * 1e6 + 5;
    vll sieve(sz, 0), mark(sz, 0);
    iota(all(sieve), 0);
    rep2(i, 2, sz) {
        for (ll j = i + i; j < sz; j += i) {
            if (mark[j])
                continue;

            sieve[j] = i;
            mark[j] = 1;
        }
    }

    vll cnt(sz + 1, 0);
    for (ll x : a) {
        if (x == 0) {
            cnt[0]++;
            continue;
        }

        ll tmp = 1;
        ll t = x;
        while (t != 1) {
            ll d = sieve[t];
            while (t % (d * d) == 0) {
                t /= d * d;
            }
            if (t % d == 0) {
                tmp *= d;
                t /= d;
            }
        }
        cnt[tmp]++;
    }

    ll ans = 0;
    rep(i, sz + 1) {
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }

    rep2(i, 1, sz + 1) {
        if (cnt[i])
            ans += cnt[0] * cnt[i];
    }

    cout << ans << endl;
}
