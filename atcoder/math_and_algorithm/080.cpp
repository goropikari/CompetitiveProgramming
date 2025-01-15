// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_bl
/*2025年01月16日 00時40分14秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
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

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;
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
    ll N, M;
    cin >> N >> M;

    map<pair<ll, ll>, ll> mp;

    vvll graph(N);
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        mp[{a, b}] = c;
        mp[{b, a}] = c;
    }

    vint visited(N, 0);
    vll dist(N, INF);
    dist[0] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
        pq;
    // cost, pos
    pq.push({0, 0});
    while (pq.size()) {
        auto [cost, pos] = pq.top();
        pq.pop();
        if (visited[pos])
            continue;
        visited[pos] = 1;

        for (auto nx : graph[pos]) {
            ll c = mp[{pos, nx}];
            ll nxcost = cost + c;
            if (dist[nx] <= nxcost) {
                continue;
            }
            dist[nx] = nxcost;
            pq.push({nxcost, nx});
        }
    }

    ll ans = dist[N - 1];
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
}
