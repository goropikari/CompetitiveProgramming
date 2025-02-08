/*https://atcoder.jp/contests/abc301/tasks/abc301_d*/
/*2025年02月05日 20時00分25秒*/
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

ll cal(string s) {
    int n = s.size();
    ll ans = 0;
    rep(i, n) {
        ans *= 2;
        ans += s[i] - '0';
    }
    return ans;
}

void solve() {
    string S;
    ll N;
    cin >> S >> N;

    string minv = S;

    for (char& c : minv) {
        if (c == '?')
            c = '0';
    }

    rep(i, S.size()) {
        if (S[i] == '?') {
            minv[i] = '1';
            if (cal(minv) > N)
                minv[i] = '0';
        }
    }

    ll ans = cal(minv);
    if (ans > N)
        ans = -1;
    cout << ans << endl;
}
