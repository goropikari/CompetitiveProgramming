// https://atcoder.jp/contests/past19-open/tasks/past19_e
// 2025年03月30日 15時59分45秒
#include <bits/stdc++.h>
#include <variant>
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

    vector<pair<int, int>> ps;
    deque<int> que;
    int i = 0;
    while (true) {
        int lpos = S.find("/*", i);
        if (lpos == string::npos)
            break;
        int rpos = S.find("*/", lpos + 2);
        if (rpos == string::npos)
            break;
        ps.push_back({lpos, rpos + 2});
        i = rpos + 2;
    }

    vint del(N, 0);
    for (auto [s, t] : ps) {
        rep2(i, s, t) del[i] = 1;
    }

    string ans = "";
    rep(i, N) {
        if (!del[i])
            ans.push_back(S[i]);
    }
    cout << ans << endl;
}
