/*https://atcoder.jp/contests/abc339/tasks/abc339_d*/
/*2025年02月22日 19時46分00秒*/
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

// const ll INF = (ll)2e18 + 9;
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

ll n;
ll sub2id(ll i, ll j) {
    return n * i + j;
}

ll state(ll i, ll j, ll ii, ll jj) {
    return n * n * sub2id(i, j) + sub2id(ii, jj);
}

tuple<ll, ll, ll, ll> tosub(ll x) {
    ll id1 = x / (n * n), id2 = x % (n * n);
    return {id1 / n, id1 % n, id2 / n, id2 % n};
}

void solve() {
    cin >> n;
    vector<string> grid(n);
    rep(i, n) cin >> grid[i];

    vector<pair<ll, ll>> ps;
    rep(i, n) rep(j, n) {
        if (grid[i][j] == 'P') {
            ps.push_back({i, j});
        }
    }

    vll di = {0, 1, 0, -1};
    vll dj = {1, 0, -1, 0};

    vll dist(n * n * n * n, INF);
    ll id = state(ps[0].first, ps[0].second, ps[1].first, ps[1].second);
    dist[id] = 0;
    queue<ll> que;
    que.push(id);
    while (que.size()) {
        ll id = que.front();
        que.pop();

        auto [i, j, ii, jj] = tosub(id);

        rep(dir, 4) {
            ll ni = i + di[dir], nj = j + dj[dir];
            ll nii = ii + di[dir], njj = jj + dj[dir];
            ni = clamp(ni, 0ll, n - 1);
            nj = clamp(nj, 0ll, n - 1);
            nii = clamp(nii, 0ll, n - 1);
            njj = clamp(njj, 0ll, n - 1);
            if (grid[ni][nj] == '#') {
                ni = i, nj = j;
            }
            if (grid[nii][njj] == '#') {
                nii = ii, njj = jj;
            }

            ll newid = state(ni, nj, nii, njj);
            if (dist[newid] > dist[id] + 1) {
                dist[newid] = dist[id] + 1;
                que.push(newid);
            }
        }
    }

    ll ans = INF;
    rep(i, n) rep(j, n) chmin(ans, dist[state(i, j, i, j)]);
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
}
