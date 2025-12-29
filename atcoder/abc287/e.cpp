/*https://atcoder.jp/contests/abc287/tasks/abc287_e*/
/*2025年03月15日 00時12分00秒*/
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

struct Node {
    ll num;
    map<char, Node*> to;

    Node() {
        num = 0;
        to = map<char, Node*>();
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    auto root = new Node();

    auto add = [&](string s) -> void {
        auto now = root;
        for (char c : s) {
            if (now->to.count(c)) {
                now = now->to[c];
                now->num++;
            } else {
                auto tmp = new Node();
                tmp->num = 1;
                now->to[c] = tmp;
                now = tmp;
            }
        }
    };

    for (auto s : S) add(s);

    ll ans = 0;
    auto dfs = [&](auto dfs, Node* now, string& s, ll depth) -> void {
        if ((ll)s.size() == depth) return;
        auto nx = now->to[s[depth]];
        if (nx->num >= 2) {
            chmax(ans, depth + 1);
            dfs(dfs, nx, s, depth + 1);
        }
    };

    for (auto s : S) {
        ans = 0;
        dfs(dfs, root, s, 0);
        cout << ans << endl;
    }
}
