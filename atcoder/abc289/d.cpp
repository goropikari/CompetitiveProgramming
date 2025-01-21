/*https://atcoder.jp/contests/abc289/tasks/abc289_d*/
/*2025年01月21日 23時31分20秒*/
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
    int N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];
    int M;
    cin >> M;
    vll B(M);
    rep(i, M) cin >> B[i];
    ll X;
    cin >> X;

    set<ll> mochi;
    rep(i, M) mochi.insert(B[i]);

    vint st(X + 1, 0);
    st[0] = 1;
    rep(i, X + 1) {
        if (!st[i])
            continue;
        rep(j, N) {
            int k = i + A[j];
            if (k > X)
                continue;
            if (mochi.count(k))
                continue;
            st[k] = 1;
        }
    }
    yesno(st[X]);
}
