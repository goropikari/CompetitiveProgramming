/*https://atcoder.jp/contests/abc333/tasks/abc333_e*/
/*2025年03月03日 04時30分59秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <numeric>
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
    int n;
    cin >> n;
    vint t(n), x(n);
    rep(i, n) {
        cin >> t[i] >> x[i];
        x[i]--;
    }

    vint used(n, 0);
    vvint monstar(n), potion(n);
    rep(i, n) {
        if (t[i] == 1) {
            potion[x[i]].push_back(i);
        } else {
            auto& v = potion[x[i]];
            if (v.size() == 0) {
                cout << -1 << endl;
                return;
            }
            int id = v.back();
            v.pop_back();
            used[id]++;
        }
    }

    int cnt = 0, mx = 0;
    vint ans;
    rep(i, n) {
        if (t[i] == 1) {
            if (used[i]) {
                ans.push_back(1);
                cnt++;
                chmax(mx, cnt);
            } else {
                ans.push_back(0);
            }
        } else {
            cnt--;
        }
    }

    cout << mx << endl;
    print(ans);
}
