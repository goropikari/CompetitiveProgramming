/*https://atcoder.jp/contests/abc382/tasks/abc382_c*/
/*2025年01月08日 21時56分44秒*/
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
    int N, M;
    cin >> N >> M;
    vll A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    vector<pair<ll, ll>> bp;
    rep(i, M) bp.push_back({B[i], i});

    vector<int> ans(M, -1);

    sort(rall(bp));
    int i = 0, j = 0;
    while (i < N && j < M) {
        auto [b, id] = bp[j];
        if (A[i] <= b) {
            ans[id] = i + 1;
            j++;
        } else {
            i++;
        }
    }
    for (auto x : ans)
        cout << x << endl;
}
