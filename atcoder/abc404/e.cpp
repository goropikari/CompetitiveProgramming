// https://atcoder.jp/contests/abc404/tasks/abc404_e
// 2025年05月03日 21時36分59秒
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

    ll N;
    cin >> N;
    vll C(N), A(N);
    rep2(i, 1, N) cin >> C[i];
    rep2(i, 1, N) cin >> A[i];

    vint bean_id;
    rep(i, N) {
        if (A[i])
            bean_id.push_back(i);
    }
    reverse(all(bean_id));
    A[0] = 1;

    ll ans = 0;
    for (int x : bean_id) {
        ll l = x - C[x], r = x;
        ll cnt = 0;
        while (true) {
            cnt++;
            ll tmpl = l;
            int ok = 0;
            rep2(i, l, r) {
                chmin(tmpl, i - C[i]);
                if (A[i]) {
                    ok = 1;
                }
            }
            if (ok) {
                ans += cnt;
                break;
            }
            r = l;
            l = tmpl;
        }
    }
    cout << ans << endl;
}
