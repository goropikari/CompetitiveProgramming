/*https://atcoder.jp/contests/abc370/tasks/abc370_d*/
/*2025年02月22日 14時36分06秒*/
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
    int h, w, q;
    cin >> h >> w >> q;
    vint rq(q), cq(q);
    rep(i, q) {
        cin >> rq[i] >> cq[i];
        rq[i]--, cq[i]--;
    }

    vector<set<int>> rows(h), cols(w);
    rep(i, h) rep(j, w) {
        rows[i].insert(j);
        cols[j].insert(i);
    }

    rep(i, q) {
        int r = rq[i], c = cq[i];
        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            rep(i, 2) {
                int rl, rr;
                rl = rr = c;
                auto rit = rows[r].lower_bound(c);
                if (rit != rows[r].end()) {
                    rr = *rit;
                }
                if (rit != rows[r].begin()) {
                    rit--;
                    rl = *rit;
                }
                rows[r].erase(rl);
                rows[r].erase(rr);
                cols[rl].erase(r);
                cols[rr].erase(r);
                swap(r, c);
                swap(rows, cols);
            }
        }
    }

    ll ans = 0;
    for (auto s : rows)
        ans += s.size();
    cout << ans << endl;
}
