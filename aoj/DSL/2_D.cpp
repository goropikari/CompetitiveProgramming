/*https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D*/
/*2025年03月08日 00時37分06秒*/
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

struct RUQ {
    vector<ll> seg;
    vint updated_at;
    ll e = (1ll << 31) - 1;
    int len;
    int cnt = 0;

    RUQ(int n) {
        rep(i, 30) {
            if (n <= (1 << i)) {
                len = 1 << i;
                break;
            }
        }
        seg.resize(len * 2, e);
        updated_at.resize(len * 2, -1);
    }

    void update(int l, int r, ll x) {
        cnt++;
        l += len, r += len;
        while (l < r) {
            if (l & 1) {
                seg[l] = x;
                updated_at[l] = cnt;
                l++;
            }
            l /= 2;
            if (r & 1) {
                seg[r - 1] = x;
                updated_at[r - 1] = cnt;
                r--;
            }
            r /= 2;
        }
    }

    void update_rec(int l, int r, ll x) {
        cnt++;
        _update_rec(l, r, 0, len, x, 1);
    }

    void _update_rec(int ql, int qr, int sl, int sr, ll x, int p) {
        if (sr <= ql || qr <= sl)
            return;
        if (ql <= sl && sr <= qr) {
            seg[p] = x;
            updated_at[p] = cnt;
            return;
        }
        int sm = (sl + sr) / 2;
        _update_rec(ql, qr, sl, sm, x, p * 2);
        _update_rec(ql, qr, sm, sr, x, p * 2 + 1);
    }

    ll find(int p) {
        p += len;
        ll ans = seg[p];
        int t = updated_at[p];
        while (p / 2) {
            p /= 2;
            ll nv = seg[p];
            ll nt = updated_at[p];
            if (nt > t) {
                ans = nv;
                t = nt;
            }
        }
        return ans;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    RUQ seg(n);

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            // seg.update(s, t + 1, x);
            seg.update_rec(s, t + 1, x);
        } else {
            int id;
            cin >> id;
            cout << seg.find(id) << '\n';
        }
    }
}
