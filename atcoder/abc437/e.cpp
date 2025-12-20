// https://atcoder.jp/contests/abc437/tasks/abc437_e
// Sat 20 Dec 2025 09:26:22 PM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
// const int INF = (int)2e9 + 7;

template <typename T>
void chmin(T& a, T b) { a = min(a, b); }
template <typename T>
void chmax(T& a, T b) { a = max(a, b); }

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

void yesno(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

void Yes() { yesno(true); }

void No() { yesno(false); }

// ceil(a/b)
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

// floor(a/b)
ll floor(ll a, ll b) { return a / b; }

void solve();

int main() {
    solve();
    return 0;
}

struct Node {
    vll ids;
    map<ll, Node*> next_node;
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<Node*> nodes(N + 1, new Node());

    rep(i, N) {
        int id = i + 1;
        ll x, y;
        cin >> x >> y;
        Node* node = nodes[x];
        auto& next_node = node->next_node;
        if (next_node.count(y)) {
            next_node[y]->ids.push_back(id);
        } else {
            Node* tmp_node = new Node();
            tmp_node->ids.push_back(id);
            next_node[y] = tmp_node;
        }
        nodes[id] = next_node[y];
    }

    vll ans;
    auto dfs = [&](auto dfs, Node* now) -> void {
        for (auto x : now->ids) ans.push_back(x);
        for (auto [k, v] : now->next_node) dfs(dfs, v);
    };
    dfs(dfs, nodes[0]);

    print(ans);
}
