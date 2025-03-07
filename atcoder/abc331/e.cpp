/*https://atcoder.jp/contests/abc331/tasks/abc331_e*/
/*2025年02月23日 19時24分50秒*/
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
    ll n, m, l;
    cin >> n >> m >> l;
    vll a(n), b(m), c(l), d(l);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    rep(i, l) {
        cin >> c[i] >> d[i];
        c[i]--, d[i]--;
    }

    vector<pair<ll, int>> B;
    rep(i, m) B.push_back({b[i], i});

    sort(rall(B));

    set<pair<int, int>> ban;
    rep(i, l) ban.insert({c[i], d[i]});

    ll ans = 0;
    rep(i, n) {
        rep(j, m) {
            if (!ban.count({i, B[j].second})) {
                chmax(ans, a[i] + B[j].first);
                break;
            }
        }
    }
    cout << ans << endl;
}
