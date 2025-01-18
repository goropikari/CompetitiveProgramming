/*https://atcoder.jp/contests/abc389/tasks/abc389_c*/
/*2025年01月18日 21時04分38秒*/
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
    ll Q;
    cin >> Q;

    ll sub = 0;

    // head pos, length
    deque<pair<ll, ll>> que;
    rep(i, Q) {
        ll x;
        cin >> x;
        if (x == 1) {
            ll l;
            cin >> l;
            if (que.size()) {
                auto [prevpos, prevlen] = que.back();
                que.push_back({prevpos + prevlen, l});
            } else {
                que.push_back({0, l});
            }
        } else if (x == 2) {
            auto [pos, len] = que.front();
            que.pop_front();
            sub = pos + len;
            if (que.empty())
                sub = 0;
        } else {  // x==3
            ll k;
            cin >> k;
            k--;
            cout << que[k].first - sub << endl;
        }
    }
}
