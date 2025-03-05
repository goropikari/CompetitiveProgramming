/*https://atcoder.jp/contests/abc340/tasks/abc340_e*/
/*2025年03月02日 11時44分26秒*/
#include <atcoder/all>
using namespace atcoder;
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

struct S {
    long long value;
    int size;
};
using F = long long;

S op(S a, S b) {
    return {a.value + b.value, a.size + b.size};
}
S e() {
    return {0, 0};
}
S mapping(F f, S x) {
    return {x.value + f * x.size, x.size};
}
F composition(F f, F g) {
    return f + g;
}
F id() {
    return 0;
}

void solve() {
    int N, M;
    cin >> N >> M;

    vll A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    std::vector<S> v(N, {0, 1});
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    rep(i, N) seg.apply(i, i + 1, A[i]);

    for (ll b : B) {
        ll x = seg.get(b).value;
        seg.apply(b, b + 1, -x);
        ll q = x / N;
        ll r = x % N;
        if (q) {
            seg.apply(0, N, q);
        }

        b++;
        if (b + r >= N) {
            seg.apply(b, N, 1);
            seg.apply(0, (b + r) % N, 1);
        } else {
            seg.apply(b, b + r, 1);
        }
    }

    rep(i, N) {
        ll x = seg.get(i).value;
        if (i != 0)
            cout << ' ';
        cout << x;
    }
    cout << endl;
}
