// https://atcoder.jp/contests/abc404/tasks/abc404_b
// 2025年05月03日 21時01分56秒
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
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

using P = pair<int, int>;

template <typename T>
struct Matrix {
    Matrix(int h, int w)
        : isSwap(false), H(h), W(w), grid(h, vector<T>(w, 0)), xid(h), yid(w) {
        rep(i, h) xid[i] = i;
        rep(i, w) yid[i] = i;
    }

    T find(int x, int y) {
        P p = index(x, y);
        return grid[p.first][p.second];
    }

    void set(int x, int y, T val) {
        P p = index(x, y);
        grid[p.first][p.second] = val;
    }

    void rotr90() {
        isSwap = !isSwap;
        vector<int> new_yid(H);
        rep(i, H) new_yid[i] = H - 1 - xid[i];
        swap(H, W);
        xid = yid;
        yid = new_yid;
    }

    void rotl90() {
        isSwap = !isSwap;
        vector<int> new_xid(W);
        rep(i, W) new_xid[i] = W - 1 - yid[i];
        swap(H, W);
        yid = xid;
        xid = new_xid;
    }

    void topbottom() {
        rep(i, H / 2) swap(xid[i], xid[H - 1 - i]);
    }

    void leftright() {
        rep(i, W / 2) swap(yid[i], yid[W - 1 - i]);
    }

    void transpose() {
        isSwap = !isSwap;
        swap(xid, yid);
        swap(H, W);
    }

    void print() {
        rep(i, H) {
            rep(j, W) {
                cout << find(i, j) << " ";
            }
            cout << endl;
        }
    }

   private:
    bool isSwap;
    int H, W;
    vector<vector<T>> grid;

    // 新しい行列の index と original の行列の index との対応表
    // 新しい行列の i, j 成分は
    // swap is false のとき
    //   grid[xid[i]][yid[j]]
    // swap is true のとき
    //   grid[yid[j]][xid[i]]
    vector<int> xid, yid;

    pair<int, int> index(int x, int y) {
        int i = xid[x];
        int j = yid[y];
        if (isSwap)
            swap(i, j);
        return {i, j};
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    Matrix<char> S(N, N), T(N, N);
    rep(i, N) rep(j, N) {
        char c;
        cin >> c;
        S.set(i, j, c);
    }
    rep(i, N) rep(j, N) {
        char c;
        cin >> c;
        T.set(i, j, c);
    }

    ll ans = INF;
    rep(i, 4) {
        if (i != 0)
            S.rotr90();
        ll cnt = 0;
        rep(i, N) rep(j, N) {
            if (S.find(i, j) != T.find(i, j))
                cnt++;
        }
        chmin(ans, cnt + i);
    }
    cout << ans << endl;
}
