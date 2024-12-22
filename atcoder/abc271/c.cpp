// https://atcoder.jp/contest/abc271/tasks/abc271_c
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

void solve() {
    int N;
    cin >> N;
    vint a(N);
    rep(i, N) cin >> a[i];
    set<int> s;

    vint b;
    for (int x : a) {
        if (s.count(x)) {
            b.push_back(INF);
        } else {
            b.push_back(x);
            s.insert(x);
        }
    }
    sort(all(b));
    // print(b);

    int cnt = 0;
    int nx = 1;
    int i = 0;
    while (b.size() > 0 && i < b.size()) {
        if (b[i] == nx) {
            i++;
        } else if (b.size() - i >= 2) {
            b.pop_back();
            b.pop_back();
        } else {
            break;
        }
        cnt++;
        nx++;
    }
    cout << cnt << endl;
}

int main() {
    solve();
    return 0;
}
