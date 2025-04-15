// https://atcoder.jp/contests/past18-open/tasks/past18_g
// 2025年04月16日 01時24分22秒
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

    int n;
    cin >> n;
    vint a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    auto check = [](vint x, vint y) -> bool {
        int m = x.size();
        int cont = 0;
        int cnt = 0;

        if (x == y)
            return true;
        rep(i, m) {
            if (i + 1 < m)
                cont += x[i] == x[i + 1];
            if (x[i] == y[i])
                continue;
            if (i + 1 < m) {
                cnt++;
                swap(x[i], x[i + 1]);
            }
        }
        if (x != y)
            return false;
        if (cnt > 2)
            return false;
        if (cnt == 2)
            return true;
        if (cnt == 1 && cont > 0) {
            // 連続している部分を先んじて swap しておく or 操作が終わった後に連続している部分があったらその部分を swap する
            return true;
        }
        return false;
    };

    bool ok = false;
    ok = ok || check(a, b);
    reverse(all(a));
    reverse(all(b));
    ok = ok || check(a, b);
    yesno(ok);
}
