/*https://atcoder.jp/contests/abc374/tasks/abc374_d*/
/*2025年01月27日 22時32分23秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
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

const ll INF = (ll)2e18 + 9;
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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

ll N, S, T;
vll A;
vll B;
vll C;
vll D;

double cal(vint track, int state) {
    vector<pair<ll, ll>> nodes = {{0, 0}};
    for (int i : track) {
        if (state & (1 << i)) {
            nodes.push_back({C[i], D[i]});
            nodes.push_back({A[i], B[i]});
        } else {
            nodes.push_back({A[i], B[i]});
            nodes.push_back({C[i], D[i]});
        }
    }

    double res = 0.0;
    for (int i = 0; i < nodes.size() - 1; i += 2) {
        double dx = nodes[i].first - nodes[i + 1].first;
        double dy = nodes[i].second - nodes[i + 1].second;
        res += sqrt(dx * dx + dy * dy) / (double)S;
    }

    return res;
}

void solve() {
    cin >> N >> S >> T;
    A = vll(N);
    B = vll(N);
    C = vll(N);
    D = vll(N);
    rep(i, N) cin >> A[i] >> B[i] >> C[i] >> D[i];

    vint track(N);
    iota(all(track), 0);

    double offset = 0.0;
    rep(i, N) {
        double dx = A[i] - C[i], dy = B[i] - D[i];
        offset += sqrt(dx * dx + dy * dy) / (double)T;
    }

    double ans = INF;
    do {
        rep(state, 1 << N) {
            chmin(ans, cal(track, state) + offset);
        }
    } while (next_permutation(all(track)));

    printf("%.9lf\n", ans);
}
