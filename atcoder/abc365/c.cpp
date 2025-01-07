/*https://atcoder.jp/contests/abc365/tasks/abc365_c*/
/*2025年01月07日 01時47分11秒*/
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

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;
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
    ll N, M;
    cin >> N >> M;
    ll sum = 0;
    vll A(N);
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    if (sum <= M) {
        cout << "infinite" << endl;
        return;
    }

    ll ok = 0, ng = INF;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        ll tot = 0;
        rep(i, N) {
            tot += min(mid, A[i]);
        }
        if (tot <= M) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
}
