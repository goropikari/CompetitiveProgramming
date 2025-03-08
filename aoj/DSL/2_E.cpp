/*https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E*/
/*2025年03月08日 00時14分30秒*/
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

struct RAQ {
    vll seg;
    ll e = 0;
    int len = 1;

    RAQ(int n) {
        while (n > len)
            len *= 2;
        seg.resize(len * 2, e);
    }

    ll get(int p) {
        p += len;
        ll ans = seg[p];
        while (p / 2) {
            p /= 2;
            ans += seg[p];
        }
        return ans;
    }

    void add(int l, int r, ll x) {
        l += len, r += len;
        while (l < r) {
            if (l & 1) {
                seg[l] += x;
                l++;
            }
            l /= 2;
            if (r & 1) {
                seg[r - 1] += x;
                r--;
            }
            r /= 2;
        }
    }

    void add_rec(int l, int r, ll x) {
        _add_rec(l, r, 0, len, x, 1);
    }

    void _add_rec(int ql, int qr, int sl, int sr, ll x, int p) {
        if (sr <= ql || qr <= sl)
            return;
        if (ql <= sl && sr <= qr) {
            seg[p] += x;
            return;
        }
        int sm = (sl + sr) / 2;
        _add_rec(ql, qr, sl, sm, x, p * 2);
        _add_rec(ql, qr, sm, sr, x, p * 2 + 1);
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    RAQ seg(n);

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 0) {
            int s, t;
            ll x;
            cin >> s >> t >> x;
            s--, t--;
            // seg.add(s, t + 1, x);
            seg.add_rec(s, t + 1, x);
        } else {
            int id;
            cin >> id;
            id--;
            cout << seg.get(id) << '\n';
        }
    }
}
