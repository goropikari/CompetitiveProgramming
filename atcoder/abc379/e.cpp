// https://atcoder.jp/contests/abc379/tasks/abc379_e
// 2025年04月24日 19時47分41秒
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

    int N;
    string S;
    cin >> N >> S;

    reverse(all(S));

    ll sum = 0;
    rep(i, N) {
        ll x = S[i] - '0';
        sum += x * (N - i);
    }

    vll ans(N + 1);
    rep(i, N) {
        ans[i] = sum;
        ll x = S[i] - '0';
        sum -= x * (N - i);
    }

    rep(i, N) {
        ll q = ans[i] / 10;
        ans[i + 1] += q;
        ans[i] %= 10;
    }
    if (ans.back() == 0) ans.pop_back();

    reverse(all(ans));
    for (ll x : ans) cout << x;
    cout << endl;
}
