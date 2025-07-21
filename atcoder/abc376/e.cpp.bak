/*https://atcoder.jp/contests/abc376/tasks/abc376_e*/
/*2025年02月26日 01時25分46秒*/
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

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

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
    int T;
    cin >> T;
    rep(_, T) {
        int n, k;
        cin >> n >> k;
        vll A(n), B(n);
        rep(i, n) cin >> A[i];
        rep(i, n) cin >> B[i];

        vector<pair<ll, ll>> ps;
        rep(i, n) {
            ps.emplace_back(A[i], B[i]);
        }
        sort(all(ps));

        multiset<ll> store;
        ll sum = 0;
        rep(i, k - 1) {
            ll x = ps[i].second;
            store.insert(x);
            sum += x;
        }

        ll ans = INF;
        rep2(i, k - 1, n) {
            auto [a, b] = ps[i];
            if ((int)store.size() == k - 1) {
                store.insert(b);
                sum += b;
            } else {
                auto it = prev(store.end());
                ll mx = *it;
                if (mx < b)
                    continue;
                store.erase(it);
                store.insert(b);
                sum = sum - mx + b;
            }
            chmin(ans, a * sum);
        }
        cout << ans << endl;
    }
}
