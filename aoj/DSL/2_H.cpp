/*https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H*/
/*2025年03月08日 14時28分32秒*/
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

const ll INF = (ll)2e18 + 9;
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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

struct RMQRAQ {
    vll seg;
    vll lazy;
    int len = 1;
    ll e = 0;
    ll id = INF;

    RMQRAQ(int n) {
        while (n > len)
            len *= 2;
        seg.resize(len * 2, e);
        lazy.resize(len * 2, id);
    }

    void eval(int sl, int sr, int p) {
        if (lazy[p] == id)
            return;
        seg[p] += lazy[p];
        if (sr - sl > 1) {
            ll x = lazy[p];
            if (lazy[p * 2] == id)
                lazy[p * 2] = x;
            else
                lazy[p * 2] += x;

            if (lazy[p * 2 + 1] == id)
                lazy[p * 2 + 1] = x;
            else
                lazy[p * 2 + 1] += x;
        }
        lazy[p] = id;
    }

    ll find(int l, int r) {
        auto rec = [&](auto rec, int ql, int qr, int sl, int sr, int p) -> ll {
            eval(sl, sr, p);
            if (sr <= ql || qr <= sl) {
                return id;
            }
            if (ql <= sl && sr <= qr) {
                return seg[p];
            }
            int sm = (sl + sr) / 2;
            ll lmin = rec(rec, ql, qr, sl, sm, p * 2);
            ll rmin = rec(rec, ql, qr, sm, sr, p * 2 + 1);

            return min(lmin, rmin);
        };

        return rec(rec, l, r, 0, len, 1);
    }

    void add(int s, int t, ll x) {
        auto rec = [&](auto rec, int ql, int qr, int sl, int sr, ll x, int p) {
            eval(sl, sr, p);

            if (qr <= sl || sr <= ql)
                return;
            if (ql <= sl && sr <= qr) {
                if (lazy[p] == id)
                    lazy[p] = 0;
                lazy[p] += x;
                eval(sl, sr, p);
                return;
            }

            int sm = (sl + sr) / 2;
            rec(rec, ql, qr, sl, sm, x, p * 2);
            rec(rec, ql, qr, sm, sr, x, p * 2 + 1);
            seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
        };

        rec(rec, s, t, 0, len, x, 1);
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    RMQRAQ seg(n);

    rep(i, q) {
        int com;
        cin >> com;
        if (com == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            seg.add(s, t + 1, x);
        } else {
            ll s, t;
            cin >> s >> t;
            cout << seg.find(s, t + 1) << '\n';
        }
    }
}
