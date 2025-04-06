// https://atcoder.jp/contests/past15-open/tasks/past202306_d
// 2025年04月06日 22時17分27秒
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

    ll A, B, C, D, R;
    cin >> A >> B >> C >> D >> R;
    int N = 10000;
    vint rec(N, 0);
    for (ll i = A; i < A + R; i++)
        rec[i] = 1;

    ll p = C;
    ll q = C + R;
    for (ll t = D; t <= N; t += D) {
        if (t > B && t < q) {
            for (ll j = max(t, p); j < q; j++) {
                rec[j] = 1;
            }
            break;
        }
    }

    int ok = 1;
    for (ll i = p; i < q; i++) {
        if (rec[i] == 0)
            ok = 0;
    }
    yesno(ok);
}
