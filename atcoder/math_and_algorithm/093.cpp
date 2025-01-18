// https://atcoder.jp/contests/math-and-algorithm/tasks/typical90_al
/*2025年01月16日 20時19分28秒*/
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

void solve();

int main() {
    solve();
    return 0;
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll tenth(ll t) {
    ll cnt = 0;
    while (t) {
        cnt++;
        t /= 10;
    }
    return cnt - 1;
}

ll istenth(ll x) {
    ll sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum == 1;
}

void solve() {
    ll A, B;
    cin >> A >> B;

    ll d = gcd(A, B);
    if (A / d > (ll)1e18 / B) {
        puts("Large");
    } else {
        cout << A / d * B << endl;
    }
}
