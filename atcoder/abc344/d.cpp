/*https://atcoder.jp/contests/abc344/tasks/abc344_d*/
/*2025年02月10日 00時03分14秒*/
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

void solve() {
    string t;
    cin >> t;
    int n;
    cin >> n;

    vector<vector<string>> st(n);
    rep(i, n) {
        int a;
        cin >> a;
        rep(j, a) {
            string s;
            cin >> s;
            st[i].push_back(s);
        }
    }

    map<string, int> mp;
    mp[""] = 0;
    for (auto& v : st) {
        vector<pair<string, int>> memo;
        for (auto [subs, cnt] : mp) {
            int sz = subs.size();
            for (string cand : v) {
                if (t.substr(sz, cand.size()) == cand) {
                    memo.push_back({subs + cand, cnt + 1});
                }
            }
        }

        for (auto [s, cnt] : memo) {
            if (mp.count(s)) {
                chmin(mp[s], cnt);
            } else {
                mp[s] = cnt;
            }
        }
    }

    ll ans = mp[t];
    if (ans == 0)
        ans = -1;
    cout << ans << endl;
}
