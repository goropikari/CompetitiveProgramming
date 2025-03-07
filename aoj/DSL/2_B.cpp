/*https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B*/
/*2025年03月08日 00時27分29秒*/
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

struct RSQ {
    vll seg;
    ll e = 0;
    ll len;

    RSQ(int n) {
        rep(i, n) {
            if (n <= (1 << i)) {
                len = 1 << i;
                break;
            }
        }

        seg.resize(len * 2, e);
    }

    void add(int p, ll x) {
        p += len;
        seg[p] += x;
        while (p / 2) {
            p /= 2;
            seg[p] += x;
        }
    }

    ll sum(int l, int r) {
        l += len, r += len;
        ll ans = e;

        while (l < r) {
            if (l & 1) {
                ans += seg[l];
                l++;
            }
            l /= 2;
            if (r & 1) {
                ans += seg[r - 1];
                r--;
            }
            r /= 2;
        }

        return ans;
    }

    ll sum_rec(int l, int r) {
        return _sum_rec(l, r, 0, len, 1);
    }

    ll _sum_rec(int ql, int qr, int sl, int sr, int p) {
        if (qr <= sl || sr <= ql)
            return e;
        if (ql <= sl && sr <= qr)
            return seg[p];
        int sm = (sl + sr) / 2;
        ll lsum = _sum_rec(ql, qr, sl, sm, p * 2);
        ll rsum = _sum_rec(ql, qr, sm, sr, p * 2 + 1);
        return lsum + rsum;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    RSQ seg(n);

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 0) {
            ll p, x;
            cin >> p >> x;
            p--;
            seg.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            // cout << seg.sum(l, r + 1) << '\n';
            cout << seg.sum_rec(l, r + 1) << '\n';
        }
    }
}
