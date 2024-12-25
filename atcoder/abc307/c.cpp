/*https://atcoder.jp/contests/abc307/tasks/abc307_c*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<ll,ll>;
using P = pair<int, int>;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;
// const ll MOD = (ll)1e9+9;
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

vector<string> crop(vector<string>& A) {
    int minx = INF, miny = INF, maxx = -1, maxy = -1;
    int h = A.size();
    int w = A[0].size();
    rep(i, h) rep(j, w) if (A[i][j] == '#') {
        chmin(minx, i);
        chmin(miny, j);
        chmax(maxx, i);
        chmax(maxy, j);
    }

    int newh = maxx - minx + 1;
    int neww = maxy - miny + 1;
    vector<string> ret(newh);
    rep(i, newh) {
        rep(j, neww) {
            ret[i].push_back(A[minx + i][miny + j]);
        }
    }
    return ret;
}

void solve() {
    int ha, wa;
    cin >> ha >> wa;
    vector<string> A(ha);
    rep(i, ha) cin >> A[i];

    int hb, wb;
    cin >> hb >> wb;
    vector<string> B(hb);
    rep(i, hb) cin >> B[i];

    int hx, wx;
    cin >> hx >> wx;
    vector<string> X(hx);
    rep(i, hx) cin >> X[i];

    A = crop(A);
    B = crop(B);
    X = crop(X);

    ha = A.size();
    wa = A[0].size();
    hb = B.size();
    wb = B[0].size();
    hx = X.size();
    wx = X[0].size();

    int MX = 11;
    rep(xx, MX) {
        rep(yy, MX) {
            rep(ax, MX) {
                rep(ay, MX) {
                    rep(bx, MX) {
                        rep(by, MX) {
                            vector<string> C(MX * 2);
                            int DMX = MX * 2;
                            rep(i, MX * 2) C[i] = "........................";

                            rep(i, ha) {
                                rep(j, wa) {
                                    if (A[i][j] == '#')
                                        C[ax + i][ay + j] = A[i][j];
                                }
                            }
                            rep(i, hb) {
                                rep(j, wb) {
                                    if (B[i][j] == '#')
                                        C[bx + i][by + j] = B[i][j];
                                }
                            }

                            rep(i, hx) {
                                rep(j, wx) {
                                    if (C[xx + i][yy + j] == X[i][j])
                                        C[xx + i][yy + j] = '.';
                                    else
                                        C[xx + i][yy + j] = '#';
                                }
                            }

                            bool ok = true;
                            rep(i, DMX) rep(j, DMX) {
                                if (C[i][j] == '#')
                                    ok = false;
                            }
                            if (ok) {
                                yesno(true);
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    yesno(false);
}
