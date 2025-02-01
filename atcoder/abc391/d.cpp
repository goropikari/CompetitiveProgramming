/*https://atcoder.jp/contests/abc391/tasks/abc391_d*/
/*2025年02月01日 21時19分16秒*/
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
    ll N, W;
    cin >> N >> W;

    vector<pair<ll, ll>> blocks(N);
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        x--;
        blocks[i] = {x, y};
    }

    int Q;
    cin >> Q;
    vector<pair<ll, ll>> queries(Q);
    rep(i, Q) {
        ll t, a;
        cin >> t >> a;
        a--;
        queries[i] = {t, a};
    }

    // lane[x][{y,id}]
    // x: column number
    // y: row number
    // id: block id
    vector<vector<pair<ll, ll>>> lane(W);
    rep(i, N) {
        auto [x, y] = blocks[i];
        lane[x].push_back({y, i});
    }
    for (auto& v : lane)
        sort(all(v));

    // disappear_time[i]: i 回目の消える操作が行われる時刻
    vll disappear_time(3 * N, INF);
    ll min_cnt = INF;
    for (auto& v : lane)
        chmin(min_cnt, (ll)v.size());
    rep(j, min_cnt) {
        ll t = 0;
        rep(i, W) {
            chmax(t, lane[i][j].first);
        }
        disappear_time[j] = t;
    }

    // block_disappear_time[i]:
    // block i が消える時刻
    vll block_disappear_time(N, INF);
    for (auto& v : lane) {
        rep(i, v.size()) {
            auto [_, id] = v[i];
            block_disappear_time[id] = disappear_time[i];
        }
    }
    // print(block_disappear_time);

    rep(i, Q) {
        auto [t, id] = queries[i];
        ll dt = block_disappear_time[id];
        yesno(t < dt);
    }
}
