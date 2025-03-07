/*http://localhost:5173/problem/staticrmq*/
/*2025年03月07日 23時38分09秒*/
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

struct SegmentTree {
    vll seg;
    int length;

    SegmentTree(int n) {
        rep(i, 30) {
            if (n <= (1 << i)) {
                length = 1 << i;
                break;
            }
        }
        seg.resize(length * 2, INF);
    }

    void set(int p, ll x) {
        p += length;
        seg[p] = x;
        while (p / 2) {
            p /= 2;
            seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
        }
    }

    ll prod(int l, int r) {
        l += length;
        r += length;

        ll ans = INF;
        while (l < r) {
            if (l & 1) {
                chmin(ans, seg[l]);
                l++;
            }
            l /= 2;
            if (r & 1) {
                chmin(ans, seg[r - 1]);
                r--;
            }
            r /= 2;
        }

        return ans;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    SegmentTree seg(n);
    rep(i, n) {
        ll a;
        cin >> a;
        seg.set(i, a);
    }

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        cout << seg.prod(l, r) << '\n';
    }
}
