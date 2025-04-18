/*https://atcoder.jp/contests/abc398/tasks/abc398_d*/
/*2025年03月22日 21時11分34秒*/
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

    ll n, row, col;
    cin >> n >> row >> col;
    string s;
    cin >> s;

    using P = pair<ll, ll>;
    set<P> memo;
    memo.insert({0, 0});

    int si = 0, sj = 0;

    for (char c : s) {
        if (c == 'N') {
            si++;
            row++;
        }
        if (c == 'W') {
            sj++;
            col++;
        }
        if (c == 'S') {
            si--;
            row--;
        }
        if (c == 'E') {
            sj--;
            col--;
        }
        memo.insert({si, sj});
        if (memo.count({row, col})) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;
}
