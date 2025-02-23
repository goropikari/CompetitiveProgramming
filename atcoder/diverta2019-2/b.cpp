// https://atcoder.jp/contests/diverta2019-2/tasks/diverta2019_2_b
/*2025年02月23日 21時42分33秒*/
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

struct Diff {
    ll x, y, cnt;
};

bool operator>(const Diff& a, const Diff& b) {
    return a.cnt > b.cnt;
}

bool operator<(const Diff& a, const Diff& b) {
    return a.cnt < b.cnt;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<ll, ll>> bs;
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        bs.push_back({x, y});
    }
    if (n == 1)
        bs.push_back({INF, INF});
    sort(all(bs));

    n = bs.size();
    vector<Diff> ds;
    {
        map<pair<ll, ll>, ll> cnt;
        rep(i, n) {
            rep2(j, i + 1, n) {
                auto [x1, y1] = bs[i];
                auto [x2, y2] = bs[j];

                cnt[{x2 - x1, y2 - y1}]++;
            }
        }

        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            auto [x, y] = it->first;
            ds.push_back({x, y, it->second});
        }
        sort(rall(ds));
    }

    auto [p, q, _] = ds[0];

    ll ans = 0;
    set<pair<ll, ll>> memo;
    rep(i, n) memo.insert(bs[i]);
    rep(i, n) {
        if (!memo.count(bs[i]))
            continue;
        auto [x, y] = bs[i];
        ans++;
        while (memo.count({x + p, y + q})) {
            memo.erase({x + p, y + q});
            x += p;
            y += q;
        }
    }
    cout << ans << endl;
}
