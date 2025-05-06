// https://atcoder.jp/contests/arc118/tasks/arc118_b
// 2025年05月05日 16時27分37秒
#include <bits/stdc++.h>
#include <numeric>
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

const ll INF = (ll)8e18 + 9;
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

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll K, N, M;
    cin >> K >> N >> M;
    vll A(K);
    rep(i, K) cin >> A[i];

    auto cal = [&](ll d) -> bool {
        ll rsum = 0;
        for (ll a : A) {
            rsum += (d + M * a) / N;
        }

        ll lsum = 0;
        for (ll a : A) {
            lsum += (max(0ll, (-d + M * a)) + N - 1) / N;
        }

        return lsum <= M && M <= rsum;
    };

    ll ac = INF, wa = -1;
    while (ac - wa > 1) {
        ll wj = (ac + wa) / 2;
        if (cal(wj))
            ac = wj;
        else
            wa = wj;
    }
    vll B;
    rep(i, K) {
        B.push_back((ac + M * A[i]) / N);
    }

    ll ndel = accumulate(all(B), 0ll) - M;
    rep(i, K) {
        if (ndel == 0)
            break;
        ll lower = (max(0ll, (-ac + M * A[i])) + N - 1) / N;
        ll x = min(ndel, B[i] - lower);
        B[i] -= x;
        ndel -= x;
    }
    print(B);
}
