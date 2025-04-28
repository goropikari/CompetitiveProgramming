// https://atcoder.jp/contests/abc403/tasks/abc403_e
// 2025年04月28日 16時43分42秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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

// https://www.youtube.com/live/Ujaynq2mMW4?si=T0QDmJM-3b-YL5a8&t=7922
struct Trie {
    vector<map<char, int>> to;
    Trie() : to(1) {};

    int add(string s) {
        int v = 0;
        for (char c : s) {
            if (to[v].count(c) == 0) {
                int u = to.size();
                to.push_back(map<char, int>());
                to[v][c] = u;
            }
            v = to[v][c];
        }
        return v;
    }

    vector<bool> ng;
    vint ynode;
    int ynum;
    void init() {
        ng.resize(to.size(), false);
        ynum = 0;
        ynode.resize(to.size());
    }

    void addx(int x) {
        if (ng[x])
            return;
        ng[x] = true;
        if (ynode[x] > 0)
            ynum -= ynode[x];
        for (auto [k, v] : to[x]) {
            addx(v);
        }
    }
    void addy(int x) {
        if (ng[x])
            return;
        ynum++;
        ynode[x]++;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    Trie trie;

    vector<pair<int, int>> query;
    rep(i, q) {
        int t;
        string s;
        cin >> t >> s;
        int v = trie.add(s);
        query.push_back({t, v});
    }
    trie.init();

    for (auto [t, v] : query) {
        if (t == 1) {
            trie.addx(v);
        } else {
            trie.addy(v);
        }
        cout << trie.ynum << endl;
    }
}
