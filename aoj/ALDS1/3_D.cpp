// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/3/ALDS1_3_D
/*2025年01月22日 20時34分16秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <numeric>
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
    string s;
    cin >> s;

    // id, size
    vector<pair<int, int>> ps;
    vint ls;
    int n = s.size();
    rep(i, n) {
        if (s[i] == '\\') {
            ls.push_back(i);
        } else if (s[i] == '/') {
            if (ls.size()) {
                int lid = ls.back();
                ls.pop_back();
                int sum = i - lid;
                while (ps.size() && lid < ps.back().first) {
                    auto [_, sz] = ps.back();
                    sum += sz;
                    ps.pop_back();
                }
                ps.push_back({lid, sum});
            }
        }
    }

    vint v;
    for (auto [_, sz] : ps)
        v.push_back(sz);
    cout << accumulate(all(v), 0) << '\n';
    cout << v.size();
    for (int x : v)
        cout << ' ' << x;
    cout << endl;
}
