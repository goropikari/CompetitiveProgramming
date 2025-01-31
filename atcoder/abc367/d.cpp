/*https://atcoder.jp/contests/abc367/tasks/abc367_d*/
/*2025年01月30日 00時32分17秒*/
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
    ll N, M;
    cin >> N >> M;
    vll A(N);
    rep(i, N) {
        cin >> A[i];
        A[i] %= M;
    }

    vll cumsum(2 * N + 1, 0);
    rep2(i, 0, 2 * N) {
        cumsum[i + 1] = cumsum[i] + A[i % N];
        cumsum[i + 1] %= M;
    }

    vll rem(M);
    rep(i, N) {
        rem[cumsum[i]]++;
    }

    ll ans = 0;
    rep(i, N) {
        ll r = cumsum[i];
        if (rem[r]) {
            ans += rem[r] - 1;
        }
        rem[r]--;
        rem[cumsum[i + N]]++;
    }
    cout << ans << endl;
}
