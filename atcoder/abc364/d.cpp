/*https://atcoder.jp/contests/abc364/tasks/abc364_d*/
/*2025年02月19日 22時13分13秒*/
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
    ll N, Q;
    cin >> N >> Q;
    vll a(N);
    rep(i, N) cin >> a[i];
    sort(all(a));

    rep(i, Q) {
        ll b, k;
        cin >> b >> k;

        ll wa = -1, ac = 2e8 + 5;
        while (abs(ac - wa) > 1) {
            ll wj = (ac + wa) / 2;
            auto l = lower_bound(all(a), b - wj);
            auto r = upper_bound(all(a), b + wj);
            if (r - l >= k)
                ac = wj;
            else
                wa = wj;
        }
        cout << ac << endl;
    }
}
