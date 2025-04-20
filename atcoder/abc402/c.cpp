// https://atcoder.jp/contests/abc402/tasks/abc402_c
// 2025年04月19日 21時02分48秒
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vvll A(M);
    rep(i, M) {
        int K;
        cin >> K;
        rep(j, K) {
            ll a;
            cin >> a;
            a--;
            A[i].push_back(a);
        }
    }

    vll B(N);
    rep(i, N) {
        cin >> B[i];
        B[i]--;
    }

    // shokuzai[i]: 食材 i を使っている料理の番号
    vvll shokuzai(N);
    rep(i, M) {
        for (ll a : A[i]) {
            shokuzai[a].push_back(i);
        }
    }

    // nums[i]: 料理 i が使用している食材の数
    vll nums(M, 0);
    rep(i, M) nums[i] = A[i].size();

    ll ans = 0;
    for (ll b : B) {
        for (ll i : shokuzai[b]) {
            nums[i]--;
            if (nums[i] == 0)
                ans++;
        }
        cout << ans << endl;
    }
}
