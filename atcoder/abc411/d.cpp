// https://atcoder.jp/contests/abc411/tasks/abc411_d
// 2025年06月22日 18時27分42秒
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
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
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
    cout << (x ? "Yes" : "No") << '\n';
}

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

void solve();

int main() {
    solve();
    return 0;
}

struct Node {
    int id, parent;
    string data;

    Node() {
        id = 0;
        parent = -1;
        data = "";
    }

    Node(int id, int parent, string data) : id(id), parent(parent), data(data) {}
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, Q;
    cin >> N >> Q;

    vector<Node> nodes(N + 1), tree(1);

    rep(i, Q) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            cin >> p;
            nodes[p] = nodes[0];
        }
        if (t == 2) {
            int p;
            string s;
            cin >> p >> s;
            Node node(tree.size(), nodes[p].id, s);
            tree.push_back(node);
            nodes[p] = node;
        }
        if (t == 3) {
            int p;
            cin >> p;
            nodes[0] = nodes[p];
        }
    }

    string ans = "";
    Node node = nodes[0];
    while (node.parent != -1) {
        string s = node.data;
        reverse(all(s));
        ans += s;
        node = tree[node.parent];
    }
    reverse(all(ans));
    cout << ans << endl;
}
