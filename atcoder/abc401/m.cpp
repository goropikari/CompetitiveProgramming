// https://atcoder.jp/contests/past15-open/tasks/past202306_m
// 2025年04月15日 05時31分04秒
#include <bits/stdc++.h>
#include <numeric>
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

    int N;
    cin >> N;
    vll D(N - 1);
    rep(i, N - 1) cin >> D[i];

    // d を2つのグループに分けて、それぞれのグループの和の差を最小化したい
    bitset<4000005> bs;
    int offset = 2000001;
    bs.set(offset);

    for (ll d : D) {
        bs = (bs << d) | (bs >> d);
    }

    ll ans = INF;
    rep(i, 4000005) {
        if (bs.test(i))
            chmin(ans, abs(i - offset));
    }
    cout << ans << endl;
}
