// https://atcoder.jp/contests/arc172/tasks/arc172_a
// 2025年06月30日 17時17分09秒
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
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
    cout << (x ? "Yes" : "No") << '\n';
}

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll H, W, N;
    cin >> H >> W >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    sort(rall(A));

    rep(i, N) {
        A[i] = 1 << A[i];
    }

    using P = tuple<ll, ll, ll>;
    priority_queue<P> pq;
    pq.push({min(H, W), H, W});

    int ok = 1;
    rep(i, N) {
        if (pq.size() == 0) {
            ok = 0;
            break;
        }
        auto [_, h, w] = pq.top();
        pq.pop();

        if (A[i] <= min(h, w)) {
            ll dw = w - A[i], dh = h - A[i];
            if (dw > 0) {
                pq.push({min(A[i], dw), A[i], dw});
            }
            if (dh > 0) {
                pq.push({min(dh, A[i]), dh, A[i]});
            }
            if (dw > 0 && dh > 0) {
                pq.push({min(dh, dw), dh, dw});
            }
        } else {
            ok = 0;
        }
    }

    yesno(ok);
}
