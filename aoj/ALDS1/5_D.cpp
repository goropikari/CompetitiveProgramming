// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
// 2025年04月14日 01時04分23秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
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
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

struct Segtree {
    int sz;
    vll data;

    Segtree(int n) {
        int i = 0;
        while ((1 << i) < n)
            i++;
        sz = 1 << i;
        data.resize(sz * 2);
    }

    void set(int p, ll x) {
        p += sz;
        data[p] = x;
        while (p / 2) {
            p /= 2;
            data[p] = data[p * 2] + data[p * 2 + 1];
        }
    }

    ll prod(int l, int r) {
        l += sz, r += sz;
        ll ans = 0;
        while (l < r) {
            if (l % 2 == 1) {
                ans += data[l];
                l++;
            }
            l /= 2;
            if (r % 2 == 1) {
                ans += data[r - 1];
                r--;
            }
            r /= 2;
        }
        return ans;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vint A(N);
    rep(i, N) {
        cin >> A[i];
    }

    vector<pair<int, int>> ids;
    rep(i, N) {
        ids.emplace_back(A[i], i);
    }
    sort(all(ids));

    Segtree seg(N);
    ll ans = 0;
    for (auto [_, i] : ids) {
        ans += seg.prod(i, N + 1);
        seg.set(i, 1);
    }
    cout << ans << endl;
}
