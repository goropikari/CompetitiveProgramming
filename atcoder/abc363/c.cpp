/*https://atcoder.jp/contests/abc363/tasks/abc363_c*/
/*2025年01月07日 01時29分10秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
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

int N, K;
bool has_kaibun(string s) {
    rep(i, N - K + 1) {
        string t1 = s.substr(i, K);
        string t2 = t1;
        reverse(all(t2));
        if (t1 == t2)
            return true;
    }
    return false;
}

void solve() {
    string S;
    cin >> N >> K >> S;
    sort(all(S));

    ll ans = 0;
    do {
        ans += !has_kaibun(S);
    } while (next_permutation(all(S)));
    cout << ans << endl;
}
