/*https://atcoder.jp/contests/abc319/tasks/abc319_c*/
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

void solve();

int main() {
    solve();
    return 0;
}

vvint grid(3, vint(3));
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

bool check(vint& v) {
    int n = 9;
    vvint C(3, vint(3, 0));
    rep(k, n) {
        int i = v[k] / 3;
        int j = v[k] % 3;
        C[i][j] = grid[i][j];

        rep(x, 3) {
            map<int, int> mp;
            rep(y, 3) {
                mp[C[x][y]]++;
            }
            if (mp.size() == 2 && mp[0] == 1) {
                return false;
            }
        }
        rep(y, 3) {
            map<int, int> mp;
            rep(x, 3) {
                mp[C[x][y]]++;
            }
            if (mp.size() == 2 && mp[0] == 1) {
                return false;
            }
        }

        {
            map<int, int> mp1, mp2;
            rep(x, 3) {
                mp1[C[x][x]]++;
                mp2[C[x][2 - x]]++;
            }

            if (mp1.size() == 2 && mp1[0] == 1) {
                return false;
            }
            if (mp2.size() == 2 && mp2[0] == 1) {
                return false;
            }
        }
    }

    return true;
}

void solve() {
    rep(i, 3) rep(j, 3) cin >> grid[i][j];

    vint v(9);
    iota(all(v), 0);
    ll ok = 0, cnt = 0;
    do {
        cnt++;
        ok += check(v);
    } while (next_permutation(all(v)));

    printf("%.10lf\n", (double)ok / (double)cnt);
}
