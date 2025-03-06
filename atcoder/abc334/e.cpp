/*https://atcoder.jp/contests/abc334/tasks/abc334_e*/
/*2025年03月06日 23時58分08秒*/
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
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

ll h, w;
int sub2id(int i, int j) {
    return i * w + j;
}

pair<int, int> id2sub(int id) {
    return {id / w, id % w};
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    vector<string> grid(h);
    rep(i, h) cin >> grid[i];

    dsu uf(h * w);

    vint di = {0, 1, 0, -1};
    vint dj = {1, 0, -1, 0};

    ll nred = 0;
    rep(i, h) rep(j, w) {
        if (grid[i][j] == '#') {
            rep(d, 4) {
                ll ni = i + di[d], nj = j + dj[d];
                if (ni != clamp(ni, 0ll, h - 1) || nj != clamp(nj, 0ll, w - 1))
                    continue;
                if (grid[ni][nj] == '#') {
                    uf.merge(sub2id(i, j), sub2id(ni, nj));
                }
            }
        } else {
            nred++;
        }
    }

    ll nkind = 0;
    {
        set<int> memo;
        rep(i, h) rep(j, w) {
            if (grid[i][j] == '#') {
                memo.insert(uf.leader(sub2id(i, j)));
            }
        }
        nkind = memo.size();
    }

    mint ans = 0;
    rep(i, h) rep(j, w) {
        if (grid[i][j] == '.') {
            set<int> memo;
            rep(d, 4) {
                ll ni = i + di[d], nj = j + dj[d];
                if (ni != clamp(ni, 0ll, h - 1) || nj != clamp(nj, 0ll, w - 1))
                    continue;
                if (grid[ni][nj] == '#') {
                    memo.insert(uf.leader(sub2id(ni, nj)));
                }
            }
            ll sz = memo.size();
            if (sz == 0) {
                ans += nkind + 1;
            } else {
                ans += nkind - (sz - 1);
            }
        }
    }

    ans /= nred;
    cout << ans.val() << '\n';
}
