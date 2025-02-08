/*https://atcoder.jp/contests/abc300/tasks/abc300_d*/
/*2025年02月05日 02時35分47秒*/
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
    ll N;
    cin >> N;

    ll mx = (ll)1e6 + 1;
    vll isprime(mx, 1);
    isprime[0] = isprime[1] = 0;
    rep2(i, 2, mx) {
        for (ll j = i + i; j < mx; j += i) {
            isprime[j] = 0;
        }
    }

    vll p, psq;
    rep(i, mx) {
        if (isprime[i]) {
            p.push_back(i);
            psq.push_back(i * i);
        }
    }
    vll revpsq = psq;
    reverse(all(revpsq));
    for (ll& x : revpsq)
        x *= -1;

    ll ans = 0;
    int sz = p.size();
    rep(i, sz) {
        if (p[i] > 1000)
            break;
        rep2(j, i + 1, sz) {
            ll x = psq[i] * p[j];
            if (x > N)
                break;
            ll rem = N / x;
            auto it = lower_bound(all(revpsq), -rem);
            ll k = sz - 1 - distance(revpsq.begin(), it);
            if (j >= k) {
                break;
            }
            ans += k - j;
        }
    }
    cout << ans << endl;
}
