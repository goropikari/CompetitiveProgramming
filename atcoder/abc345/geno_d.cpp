#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

#define MAX_N 7
#define MAX_H 10
#define MAX_W 10

int n, h, w;
int a[MAX_N];
int b[MAX_N];
int c[MAX_H][MAX_W];
bool ans;

void solve(int unused, int curi, int curj) {
    bool can;
    while (c[curi][curj] >= 0) {
        curj++;
        if (curj >= w) {
            curi++;
            curj = 0;
        }
        if (curi >= h) break;
    }
    if (curi >= h) {
        ans = true;
        return;
    }
    rep(i, n) {
        if (unused & (1 << i)) {
            can = true;
            rep(ii, a[i]) {
                rep(jj, b[i]) {
                    if (((curi + ii) < h) && ((curj + jj) < w)) {
                        if (c[curi + ii][curj + jj] < 0)
                            c[curi + ii][curj + jj] = i;
                        else {
                            can = false;
                        }
                    } else {
                        can = false;
                    }
                }
            }
            if (can) solve(unused ^ (1 << i), curi, curj);
            rep(ii, a[i]) {
                rep(jj, b[i]) {
                    if (((curi + ii) < h) && ((curj + jj) < w)) {
                        if (c[curi + ii][curj + jj] == i) c[curi + ii][curj + jj] = -1;
                    }
                }
            }
            if (a[i] != b[i]) {
                can = true;
                rep(ii, b[i]) {
                    rep(jj, a[i]) {
                        if (((curi + ii) < h) && ((curj + jj) < w)) {
                            if (c[curi + ii][curj + jj] < 0)
                                c[curi + ii][curj + jj] = i;
                            else
                                can = false;
                        } else
                            can = false;
                    }
                }
                if (can) solve(unused ^ (1 << i), curi, curj);
                rep(ii, b[i]) {
                    rep(jj, a[i]) {
                        if (((curi + ii) < h) && ((curj + jj) < w)) {
                            if (c[curi + ii][curj + jj] == i) c[curi + ii][curj + jj] = -1;
                        }
                    }
                }
            }
        }
    }
    return;
}

int main(void) {
    cin >> n >> h >> w;
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, h) rep(j, w) c[i][j] = -1;
    ans = false;
    solve((1 << n) - 1, 0, 0);
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
