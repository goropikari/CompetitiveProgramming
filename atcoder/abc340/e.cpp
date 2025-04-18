/*https://atcoder.jp/contests/abc340/tasks/abc340_e*/
/*2025年03月07日 23時51分07秒*/
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
    int len;

    SegmentTree(int n) {
        rep(i, 30) {
            if (n <= (1 << i)) {
                len = 1 << i;
                break;
            }
        }
        seg.resize(len * 2, 0);
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
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    SegmentTree seg(n);
    rep(i, n) {
        ll a;
        cin >> a;
        seg.add(i, i + 1, a);
    }

    rep(i, m) {
        int b;
        cin >> b;
        ll x = seg.get(b);
        seg.add(b, b + 1, -x);

        b++;
        ll q = x / n;
        ll r = x % n;
        seg.add(0, n, q);
        if (b + r >= n) {
            seg.add(b, n, 1);
            seg.add(0, b + r - n, 1);
        } else {
            seg.add(b, b + r, 1);
        }
    }

    rep(i, n) {
        if (i != 0)
            cout << ' ';
        cout << seg.get(i);
    }
    cout << endl;
}
