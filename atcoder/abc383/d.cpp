// https://atcoder.jp/contests/abc383/tasks/abc383_d
// 2025年07月20日 04時15分52秒
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
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

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

// ceil(a/b)
ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

// floor(a/b)
ll floor(ll a, ll b) {
    return a / b;
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

    ll mx = (ll)2e6 + 5;
    // ll mx = 5;
    vll is_primes(mx, true);
    is_primes[0] = is_primes[1] = false;
    rep2(i, 2, mx) {
        for (int j = i + i; j < mx; j += i) {
            is_primes[j] = false;
        }
    }

    ll ans = 0;

    rep(i, mx) {
        if (!is_primes[i]) continue;
        ll t = N;
        rep(j, 8) t /= i;
        if (t) ans++;
    }

    vll prime_sqs;
    rep(i, mx) if (is_primes[i]) prime_sqs.push_back(i * i);

    int r = prime_sqs.size() - 1;
    rep(l, (ll)prime_sqs.size()) {
        ll psq = prime_sqs[l];
        while (psq * prime_sqs[r] > N && l < r) r--;
        if (l >= r) break;
        ans += r - l;
    }

    cout << ans << endl;
}
