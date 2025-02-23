/*https://atcoder.jp/contests/abc393/tasks/abc393_e*/
/*2025年02月17日 20時23分20秒*/
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
    int n, k;
    cin >> n >> k;

    vint a(n);
    rep(i, n) cin >> a[i];

    int mx = *max_element(all(a));
    vint num(mx + 1);

    for (int x : a)
        num[x]++;

    vint cnt(mx + 1, 0);
    rep2(i, 1, mx + 1) {
        for (int j = i; j <= mx; j += i) {
            cnt[i] += num[j];
        }
    }

    vint ans(mx + 1, 0);
    rep2(i, 1, mx + 1) {
        if (cnt[i] >= k) {
            for (int j = i; j <= mx; j += i) {
                ans[j] = i;
            }
        }
    }

    for (int x : a)
        cout << ans[x] << endl;
}
