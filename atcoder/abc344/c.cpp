/*https://atcoder.jp/contests/abc344/tasks/abc344_c*/
/*2024年12月31日 15時36分41秒*/
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
    int N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    int M;
    cin >> M;
    vll B(M);
    rep(i, M) cin >> B[i];

    int L;
    cin >> L;
    vll C(L);
    rep(i, L) cin >> C[i];

    set<ll> s;
    rep(i, N) rep(j, M) rep(k, L) s.insert(A[i] + B[j] + C[k]);

    int Q;
    cin >> Q;
    rep(i, Q) {
        ll x;
        cin >> x;
        yesno(s.count(x));
    }
}
