/*https://atcoder.jp/contests/abc392/tasks/abc392_e*/
/*2025年02月09日 14時30分42秒*/
#include <atcoder/all>
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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> es;
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        es.push_back({u, v});
    }

    dsu uf(n);
    // id, u, v
    vector<tuple<int, int, int>> store;
    rep(i, m) {
        auto [u, v] = es[i];
        if (uf.same(u, v)) {
            store.push_back({i, u, v});
            continue;
        }
        uf.merge(u, v);
    }

    set<int> grps;
    rep(i, n) {
        grps.insert(uf.leader(i));
    }

    // id, from, to
    vector<tuple<int, int, int>> cables;
    while (grps.size() > 1) {
        auto [id, u, v] = store.back();
        store.pop_back();

        int l = uf.leader(u);
        int tol;
        for (int x : grps) {
            if (x != l) {
                tol = x;
                break;
            }
        }
        int newl = uf.merge(v, tol);
        cables.push_back({id + 1, v + 1, tol + 1});
        if (newl != l) {
            grps.erase(l);
        }
        if (newl != tol) {
            grps.erase(tol);
        }
    }

    cout << cables.size() << endl;
    for (auto [id, u, v] : cables) {
        cout << id << ' ' << u << ' ' << v << endl;
    }
}
