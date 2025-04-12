// https://atcoder.jp/contests/past15-open/tasks/past202306_i
// 2025年04月13日 02時42分01秒
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

    int N, K;
    cin >> N >> K;
    vint A(N);
    rep(i, N) cin >> A[i];

    int mx = (int)1e6 + 5;
    vvint divs(mx);
    rep2(i, 1, mx) {
        for (int j = i; j < mx; j += i) {
            divs[j].push_back(i);
        }
    }

    vint v(mx);
    for (int a : A) {
        for (int d : divs[a]) {
            v[d]++;
        }
    }

    int ans = 1;
    rep(i, mx) {
        if (v[i] >= K)
            ans = i;
    }
    cout << ans << endl;
}
