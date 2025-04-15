// https://atcoder.jp/contests/past15-open/tasks/past202306_o
// 2025年04月15日 08時46分28秒
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

// https://drken1215.hatenablog.com/entry/2023/05/23/233000
template <class T>
T pow_mod(T A, T N, T M) {
    T res = 1 % M;
    A %= M;
    while (N) {
        if (N & 1)
            res = (res * A) % M;
        A = (A * A) % M;
        N >>= 1;
    }
    return res;
}

bool MillerRabin(long long N, vector<long long> A) {
    long long s = 0, d = N - 1;
    while (d % 2 == 0) {
        ++s;
        d >>= 1;
    }
    for (auto a : A) {
        if (N <= a)
            return true;
        long long t, x = pow_mod<__int128_t>(a, d, N);
        if (x != 1) {
            for (t = 0; t < s; ++t) {
                if (x == N - 1)
                    break;
                x = __int128_t(x) * x % N;
            }
            if (t == s)
                return false;
        }
    }
    return true;
}

bool is_prime(long long N) {
    if (N <= 1)
        return false;
    if (N == 2)
        return true;
    if (N % 2 == 0)
        return false;
    if (N < 4759123141LL)
        return MillerRabin(N, {2, 7, 61});
    else
        return MillerRabin(N, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, A, B;
    cin >> N >> A >> B;

    ll ans = 0;
    rep(i, N) {
        if (is_prime(A * i + B))
            ans++;
    }
    cout << ans << endl;
}
