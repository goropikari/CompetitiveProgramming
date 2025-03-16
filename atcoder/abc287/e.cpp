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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<string, int>> ps;
    rep(i, n) {
        string s;
        cin >> s;
        ps.emplace_back(s, i);
    }

    sort(all(ps));
    ps.insert(ps.begin(), {"_", -1});

    vint ans(n);
    n++;
    rep2(i, 1, n) {
        int mx = 0;
        auto [s, id] = ps[i];
        {
            auto [pr, _] = ps[i - 1];
            int cnt = 0;
            int len = min(s.size(), pr.size());
            rep(j, len) {
                if (s[j] == pr[j])
                    cnt++;
                else
                    break;
                ;
            }
            chmax(mx, cnt);
        }
        if (i + 1 < n) {
            auto [nx, _] = ps[i + 1];
            int cnt = 0;
            int len = min(s.size(), nx.size());
            rep(j, len) {
                if (s[j] == nx[j])
                    cnt++;
                else
                    break;
                ;
            }
            chmax(mx, cnt);
        }
        ans[id] = mx;
    }
    for (int x : ans)
        cout << x << endl;
}
