// https://atcoder.jp/contests/abc368/tasks/abc368_f
// 2025年04月11日 15時27分32秒
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    int mx = 1e5 + 5;
    vll sieve(mx, 0);
    rep2(i, 2, mx) {
        for (int j = i; j < mx; j += i) {
            if (sieve[j] == 0)
                sieve[j] = i;
        }
    }

    auto factor_sum = [&](int x) -> int {
        int ans = 0;
        while (x != 1) {
            int d = sieve[x];
            while (x % d == 0) {
                ans++;
                x /= d;
            }
        }
        return ans;
    };

    vll nim;
    rep(i, N) {
        nim.push_back(factor_sum(A[i]));
    }

    ll sum = 0;
    for (ll x : nim)
        sum ^= x;
    string ans = "Anna";
    if (sum == 0) {
        ans = "Bruno";
    }
    cout << ans << endl;
}
