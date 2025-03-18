// https://atcoder.jp/contests/typical90/tasks/typical90_b
/*2025年03月17日 00時49分55秒*/
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    rep(i, 1ll << n) {
        int cnt = 0;
        string s = "";
        int ok = 1;
        for (ll j = n - 1; j >= 0; j--) {
            if ((i >> j) & 1) {  // )
                if (cnt) {
                    cnt--;
                    s.push_back(')');
                } else {
                    ok = 0;
                    break;
                }
            } else {  // (
                cnt++;
                s.push_back('(');
            }
        }
        if (ok && cnt == 0) {
            cout << s << endl;
        }
    }
}
