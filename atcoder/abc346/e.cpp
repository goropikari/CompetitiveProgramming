/*https://atcoder.jp/contests/abc346/tasks/abc346_e*/
/*2025年02月18日 22時24分34秒*/
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
    ll h, w, m;
    cin >> h >> w >> m;
    vector<tuple<int, int, int>> oqs, qs;
    rep(i, m) {
        int t, a, x;
        cin >> t >> a >> x;
        a--;
        oqs.push_back({t, a, x});
    }

    set<pair<int, int>> memo;
    reverse(all(oqs));
    for (auto [t, a, x] : oqs) {
        if (memo.count({t, a}))
            continue;
        memo.insert({t, a});
        qs.push_back({t, a, x});
    }

    map<int, ll> color;
    set<int> row, col;
    for (auto [t, a, x] : qs) {
        if (t == 1) {  // row
            color[x] += w - col.size();
            row.insert(a);
        } else {  // col
            color[x] += h - row.size();
            col.insert(a);
        }
    }

    // color[0] +=
    //     h * w - w * row.size() - h * col.size() + row.size() * col.size();
    color[0] += (w - col.size()) * (h - row.size());

    vector<pair<ll, ll>> ans;
    for (auto it = color.begin(); it != color.end(); it++) {
        if (it->second > 0) {
            ans.push_back({it->first, it->second});
        }
    }

    cout << ans.size() << endl;
    for (auto [c, x] : ans)
        cout << c << ' ' << x << endl;
}
