/*https://atcoder.jp/contests/abc218/tasks/abc218_e*/
/*2025年02月02日 01時14分06秒*/
#include <atcoder/all>
#include <queue>
using namespace atcoder;
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

struct Edge {
    ll u, v, cost;
};

bool operator>(const Edge& a, const Edge& b) {
    return a.cost > b.cost;
}

void solve() {
    ll N, M;
    cin >> N >> M;

    vector<Edge> es(M);
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        es[i] = {a, b, c};
    }

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    for (auto e : es)
        pq.push(e);
    dsu uf(N);
    vll dust;
    while (pq.size()) {
        auto [u, v, c] = pq.top();
        pq.pop();

        if (uf.same(u, v)) {
            if (c > 0)
                dust.push_back({c});
        } else {
            uf.merge(u, v);
        }
    }

    ll ans = 0;
    for (ll x : dust) {
        if (x > 0)
            ans += x;
    }
    cout << ans << endl;
}
