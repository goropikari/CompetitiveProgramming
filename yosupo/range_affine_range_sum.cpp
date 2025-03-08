/*http://localhost:5173/problem/range_affine_range_sum*/
/*2025年03月08日 15時37分31秒*/
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

struct RARS {
    vector<mint> seg;
    vector<pair<mint, mint>> lazy;
    int len = 1;
    ll e = 0;
    pair<mint, mint> id = {1, 0};

    RARS(int n) {
        while (n > len)
            len *= 2;
        seg.resize(len * 2, e);
        lazy.resize(len * 2, id);
    }

    void eval(int l, int r, int p) {
        if (lazy[p] == id)
            return;
        auto [b, c] = lazy[p];
        seg[p] = seg[p] * b + c * (r - l);

        if (r - l > 1) {
            rep(i, 2) {
                auto [ob, oc] = lazy[p * 2 + i];
                lazy[p * 2 + i] = {b * ob, b * oc + c};
            }
        }

        lazy[p] = id;
    }

    void add(int l, int r, ll b, ll c) {
        auto _add = [&](auto _add, int ql, int qr, int sl, int sr, ll b, ll c, int p) {
            eval(sl, sr, p);
            if (sr <= ql || qr <= sl)
                return;
            if (ql <= sl && sr <= qr) {
                auto [ob, oc] = lazy[p];
                lazy[p] = {b * ob, b * oc + c};
                eval(sl, sr, p);
                return;
            }

            int sm = (sl + sr) / 2;
            _add(_add, ql, qr, sl, sm, b, c, p * 2);
            _add(_add, ql, qr, sm, sr, b, c, p * 2 + 1);
            seg[p] = seg[p * 2] + seg[p * 2 + 1];
        };

        _add(_add, l, r, 0, len, b, c, 1);
    }

    mint sum(int l, int r) {
        auto _sum = [&](auto _sum, int ql, int qr, int sl = 0, int sr = -1, int p = 1) -> mint {
            if (sr < 0)
                sr = len;

            eval(sl, sr, p);
            if (sr <= ql || qr <= sl)
                return e;
            if (ql <= sl && sr <= qr) {
                return seg[p];
            }

            int sm = (sl + sr) / 2;
            mint lsum = _sum(_sum, ql, qr, sl, sm, p * 2);
            mint rsum = _sum(_sum, ql, qr, sm, sr, p * 2 + 1);

            return lsum + rsum;
        };

        return _sum(_sum, l, r);
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    RARS seg(n);

    rep(i, n) {
        ll a;
        cin >> a;
        seg.add(i, i + 1, 0, a);
    }

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 0) {
            ll l, r, b, c;
            cin >> l >> r >> b >> c;
            seg.add(l, r, b, c);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << seg.sum(l, r).val() << '\n';
        }
    }
}
