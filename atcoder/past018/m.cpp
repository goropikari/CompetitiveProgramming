// https://atcoder.jp/contests/past18-open/tasks/past18_m
// 2025年04月24日 19時35分48秒
#include <bits/stdc++.h>
#include <atcoder/all>
#include <atcoder/segtree.hpp>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
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
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

struct Group {
    set<int> s;
    ll sum;
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, S;
    cin >> N >> M >> S;
    vll A(N);
    rep(i, N) cin >> A[i];

    vector<pair<ll, ll>> dislikes(M);
    rep(i, M) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        dislikes[i] = {x, y};
    }

    vvint dis(N);
    for (auto [u, v] : dislikes) {
        dis[u].push_back(v);
        dis[v].push_back(u);
    }

    int ans = N;
    auto dfs = [&](auto dfs, vector<Group> v = vector<Group>(), int depth = 0) -> void {
        if (ans <= v.size())
            return;
        if (depth == N) {
            chmin(ans, (int)v.size());
            // cout << ans << endl;
            return;
        }

        rep(i, v.size()) {
            if (v[i].sum + A[depth] <= S) {
                int ok = 1;
                for (int x : dis[depth]) {
                    if (v[i].s.count(x)) {
                        ok = 0;
                        break;
                    }
                }
                if (!ok)
                    continue;
                v[i].s.insert(depth);
                v[i].sum += A[depth];
                dfs(dfs, v, depth + 1);
                v[i].s.erase(depth);
                v[i].sum -= A[depth];
            }
        }
        v.emplace_back(set<int>({depth}), A[depth]);
        dfs(dfs, v, depth + 1);
    };

    dfs(dfs);

    cout << ans << endl;
}
