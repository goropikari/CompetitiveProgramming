/*https://atcoder.jp/contests/abc259/tasks/abc259_c*/
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

vector<pair<char, int>> cal(string S) {
    char prev = '_';
    int cnt = 0;
    S.push_back('_');
    vector<pair<char, int>> v;
    rep(i, S.size()) {
        if (prev == S[i]) {
            cnt++;
        } else {
            v.push_back({prev, cnt});
            cnt = 1;
        }
        prev = S[i];
    }

    return v;
}

void solve() {
    string S, T;
    cin >> S >> T;

    vector<pair<char, int>> sq = cal(S), tq = cal(T);
    if (sq.size() != tq.size()) {
        yesno(false);
        return;
    }

    int n = sq.size();
    bool ok = true;
    rep(i, n) {
        if (sq[i].first != tq[i].first)
            ok = false;
        if (sq[i].second == 1 && tq[i].second > 1)
            ok = false;
        if (sq[i].second > tq[i].second)
            ok = false;
    }

    yesno(ok);
}

int main() {
    solve();
    return 0;
}
