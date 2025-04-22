// https://atcoder.jp/contests/past19-open/tasks/past19_l
// 2025年03月31日 07時51分22秒
#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using namespace std;
using vint = vector<int>;

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
    vint B(N);
    rep(i, N) cin >> B[i];

    bool next_up = true;
    rep2(i, 1, N) {
        if (B[0] != B[i]) {
            next_up = B[0] < B[i];
            break;
        }
    }

    int ans = 1;
    int v = B[0];
    rep2(i, 1, N) {
        if (next_up && v < B[i]) {  // next up
            ans++;
            next_up = false;
        }
        if (!next_up && v > B[i]) {  // next down
            ans++;
            next_up = true;
        }
        v = B[i];
    }

    cout << ans << '\n';
}
