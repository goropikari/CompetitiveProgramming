/*https://atcoder.jp/contests/abc216/tasks/abc216_e*/
/*2025年03月16日 02時08分51秒*/
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

ll sum(ll b, ll a) {
    return a * (a + 1) / 2 - b * (b + 1) / 2;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vll a(n);
    rep(i, n) cin >> a[i];
    sort(rall(a));

    {
        ll acc = accumulate(all(a), 0ll);
        if (acc <= k) {
            ll ans = 0;
            rep(i, n) {
                ans += a[i] * (a[i] + 1) / 2;
            }
            cout << ans << endl;
            return;
        }
    }

    ll ac = INF, wa = -1;
    while (abs(wa - ac) > 1) {
        ll wj = (ac + wa) / 2;
        ll cnt = 0;
        rep(i, n) {
            if (a[i] - wj > 0)
                cnt += a[i] - wj;
            else
                break;
        }
        if (cnt < k) {
            ac = wj;
        } else {
            wa = wj;
        }
    }

    ll ans = 0;
    ll cnt = 0;
    rep(i, n) {
        ll x = a[i];
        if (x > ac) {
            ans += (sum(ac, x));
            cnt += x - ac;
        }
    }
    ans += ac * (k - cnt);
    cout << ans << endl;
}
