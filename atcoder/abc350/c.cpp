/*https://atcoder.jp/contests/abc350/tasks/abc350_c*/
/*2024年12月31日 22時59分05秒*/
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
    int N;
    cin >> N;
    vint A(N);
    rep(i, N) {
        cin >> A[i];
        A[i]--;
    }

    map<int, int> mp;
    rep(i, N) mp[A[i]] = i;

    vector<pair<int, int>> p;
    rep(i, N - 1) {
        if (A[i] == i)
            continue;
        int a = mp[i];
        int b = A[i];
        swap(mp[i], mp[b]);
        swap(A[a], A[i]);
        int x = i + 1, y = a + 1;
        if (x > y)
            swap(x, y);
        p.push_back({x, y});
    }

    cout << p.size() << endl;
    for (auto [x, y] : p) {
        cout << x << ' ' << y << endl;
    }
}
