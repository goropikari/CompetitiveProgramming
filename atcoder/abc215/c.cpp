// https://atcoder.jp/contest/abc215/tasks/abc215_c
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
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

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;
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

vector<string> ans;

void dfs(string& cand, string s, int watch) {
    if (s.size() == cand.size()) {
        ans.push_back(s);
        return;
    }

    int n = cand.size();
    rep(i, n) {
        if (!(watch & (1 << i))) {
            s.push_back(cand[i]);
            dfs(cand, s, watch | (1 << i));
            s.pop_back();
        }
    }
}

void solve() {
    string s;
    int k;
    cin >> s >> k;
    dfs(s, "", 0);
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    cout << ans[k - 1] << endl;
}

int main() {
    solve();
    return 0;
}
