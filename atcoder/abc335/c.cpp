/*https://atcoder.jp/contests/abc335/tasks/abc335_c*/
/*2024年12月29日 01時59分59秒*/
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

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<pair<int, int>> head = {{1, 0}};
    rep(i, Q) {
        int kind;
        cin >> kind;
        if (kind == 1) {
            char c;
            cin >> c;
            auto [x, y] = head.back();
            if (c == 'R') {
                x++;
            } else if (c == 'L') {
                x--;
            } else if (c == 'U') {
                y++;
            } else {  // D
                y--;
            }
            head.push_back({x, y});
        } else {
            int p;
            cin >> p;
            int cnt = head.size();
            if (cnt - p >= 0) {
                auto [x, y] = head[cnt - p];
                cout << x << ' ' << y << endl;
            } else {
                cout << p - cnt + 1 << ' ' << 0 << endl;
            }
        }
    }
}
