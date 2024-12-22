/*https://atcoder.jp/contests/abc257/tasks/abc257_c*/
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
    string S;
    cin >> N >> S;
    vint kw, aw;
    rep(i, N) {
        int w;
        cin >> w;
        if (S[i] == '0')
            kw.push_back(w);
        else
            aw.push_back(w);
    }

    if (kw.size() == 0 || aw.size() == 0) {
        cout << N << endl;
        return;
    }

    sort(all(kw));
    sort(all(aw));

    int ans = 0;
    rep(i, aw.size()) {
        int a = aw[i];
        auto it = lower_bound(all(kw), a);
        chmax(ans, (int)aw.size() - i + (int)distance(kw.begin(), it));
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
