/*https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A*/
/*2025年03月07日 22時08分46秒*/
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

struct RMQ {
    vector<ll> data;
    ll e = (1ll << 31) - 1;
    int length;

    RMQ(int n) {
        rep(i, 30) {
            if (n <= (1 << i)) {
                length = 1 << i;
                break;
            }
        }
        data.resize(length * 2, e);
    }

    void set(int p, ll x) {
        p += length;
        data[p] = x;
        while (p / 2) {
            p /= 2;
            data[p] = min(data[2 * p], data[2 * p + 1]);
        }
    }

    ll prod(int l, int r) {
        l += length, r += length;
        ll ans = (1ll << 31) - 1;
        while (l < r) {
            if (l % 2 == 1) {
                ans = min(ans, data[l]);
                l++;
            }
            l /= 2;
            if (r % 2 == 1) {
                ans = min(ans, data[r - 1]);
                r--;
            }
            r /= 2;
        }

        return ans;
    }

    ll prod_rec(int l, int r) {
        return _prod_rec(l, r, 0, length, 1);
    }

    ll _prod_rec(int ql, int qr, int sl, int sr, int p) {
        if (qr <= sl || sr <= ql)
            return e;
        if (ql <= sl && sr <= qr)
            return data[p];
        int sm = (sl + sr) / 2;
        ll lmin = _prod_rec(ql, qr, sl, sm, p * 2);
        ll rmin = _prod_rec(ql, qr, sm, sr, p * 2 + 1);
        return min(lmin, rmin);
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    RMQ seg(n);

    rep(i, q) {
        int com, x, y;
        cin >> com >> x >> y;

        if (com == 0) {
            seg.set(x, y);
        } else {
            // cout << seg.prod(x, y + 1) << '\n';
            cout << seg.prod_rec(x, y + 1) << '\n';
        }
    }
}
