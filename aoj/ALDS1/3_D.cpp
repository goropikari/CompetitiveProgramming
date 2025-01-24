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

    vector<pair<char, ll>> v = {{'_', -1}};
    // area, pos
    vector<pair<ll, ll>> area;
    int n = s.size();
    rep(i, n) {
        if (s[i] == '\\') {
            v.push_back({s[i], i});
        }
        if (s[i] == '/') {
            auto [c, x] = v.back();
            if (c == '\\') {
                v.pop_back();
                if (area.size() == 0) {
                    area.push_back({i - x, x});
                } else {
                    ll sum = i - x;
                    while (area.size() > 0 && x < area.back().second) {
                        sum += area.back().first;
                        area.pop_back();
                    }
                    area.push_back({sum, x});
                }
            }
        }
    }

    ll sum = 0;
    rep(i, area.size()) sum += area[i].first;
    cout << sum << endl;
    cout << area.size();
    for (auto [a, _] : area)
        cout << ' ' << a;
    cout << endl;
}
