/*https://atcoder.jp/contests/abc364/tasks/abc364_c*/
/*2025年01月07日 01時38分25秒*/
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

void solve() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vll A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    sort(rall(A));
    sort(rall(B));

    ll suma = 0, sumb = 0;
    ll cnta = 0, cntb = 0;
    rep(i, N) {
        cnta++;
        suma += A[i];
        if (suma > X)
            break;
    }
    rep(i, N) {
        cntb++;
        sumb += B[i];
        if (sumb > Y)
            break;
    }

    cout << min(cnta, cntb) << endl;
}
