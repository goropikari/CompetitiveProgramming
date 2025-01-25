/*https://atcoder.jp/contests/abc360/tasks/abc360_d*/
/*2025年01月25日 12時13分46秒*/
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
    ll N, T;
    cin >> N >> T;
    string S;
    cin >> S;
    vll X(N);
    rep(i, N) cin >> X[i];

    vll L, R;
    rep(i, N) {
        if (S[i] == '0') {
            L.push_back(X[i]);
        } else {
            R.push_back(X[i]);
        }
    }

    sort(all(L)), sort(all(R));
    R.push_back(INF);

    ll ans = 0, k = 0;
    int j = 0;
    rep(i, L.size()) {
        while (j < R.size() && (L[i] - R[j]) > T * 2) {
            j++;
        }
        while (k < R.size() && (L[i] > R[k])) {
            k++;
        }
        ans += k - j;
    }
    cout << ans << endl;
}
