// https://atcoder.jp/contests/abc102/tasks/arc100_b
// Wed 04 Mar 2026 12:59:21 AM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define pb push_back
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

template <typename T>
bool chmin(T& a, T b) {
    bool change = a > b;
    a = min(a, b);
    return change;
}
template <typename T>
bool chmax(T& a, T b) {
    bool change = a < b;
    a = max(a, b);
    return change;
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

template <typename T>
void vprint(vector<T> v) {
    for (auto x : v) cout << x << '\n';
}

void yesno(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

void Yes() { yesno(true); }

void No() { yesno(false); }

// ceil(a/b)
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

// floor(a/b)
ll floor(ll a, ll b) { return a / b; }

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    vll cm(N + 1), rcm(N + 1);
    rep(_, 2) {
        rep(i, N) cm[i + 1] += cm[i] + A[i];
        swap(cm, rcm);
        reverse(all(A));
    }

    auto cal = [](vll& cm, int l, int r) -> ll {
        ll L = cm[l] - cm[0];
        ll R = cm[r] - cm[l];
        return abs(L - R);
    };

    vll ids(N + 1), rids(N + 1);
    {
        int l = 1;
        rep2(r, 2, N + 1) {
            ll L = cm[l] - cm[0], R = cm[r] - cm[l];
            ll d = abs(L - R);
            while (l + 1 < r && chmin(d, cal(cm, l + 1, r))) l++;
            ids[r] = l;
        }
    }
    {
        int l = 1;
        rep2(r, 2, N + 1) {
            ll L = rcm[l] - rcm[0], R = rcm[r] - rcm[l];
            ll d = abs(L - R);
            while (l + 1 < r && chmin(d, cal(rcm, l + 1, r))) {
                l++;
            }
            rids[r] = l;
        }
    }

    ll ans = INF;

    rep2(r, 2, N - 1) {
        int l1 = ids[r];
        int r2 = N - r;
        int l2 = rids[r2];

        vll v = {cm[l1] - cm[0], cm[r] - cm[l1], rcm[r2] - rcm[l2], rcm[l2] - rcm[0]};
        ll mx = *max_element(all(v));
        ll mi = *min_element(all(v));
        chmin(ans, mx - mi);
    }

    cout << ans << endl;
}
