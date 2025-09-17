// https://atcoder.jp/contests/code-festival-2014-quala/submissions/236572
#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;

string A;
int K;
int64 num;
int64 ans;
bool rrec(int used, int idx, bool free, bool ue, int64 value) {
    if (idx == A.size()) {
        ans = min(value - num, ans);
        return true;
    }
    int64 ret = INF;
    int begin = (ue ? 0 : A[idx] - '0');
    for (int i = begin; i <= 9; i++) {
        if (__builtin_popcount(used | (1 << i)) > K) continue;
        if (free == false && i == 0) {
            if (rrec(used, idx + 1, false, ue | (i != begin), value * 10 + i)) return true;
        } else {
            if (rrec(used | (1 << i), idx + 1, true, ue | (i != begin), value * 10 + i)) return true;
        }
    }
    return false;
}

bool rec(int used, int idx, bool free, bool ue, int64 value) {
    if (idx == A.size()) {
        ans = num - value;
        return true;
    }

    int64 ret = INF;
    int end = (ue ? 9 : A[idx] - '0');
    for (int i = end; i >= 0; i--) {
        if (__builtin_popcount(used | (1 << i)) > K) continue;
        if (free == false && i == 0) {
            if (rec(used, idx + 1, false, ue | (i != end), value * 10 + i)) return true;
        } else {
            if (rec(used | (1 << i), idx + 1, true, ue | (i != end), value * 10 + i)) return true;
        }
    }
    // return dp[used][idx][free][ue] = ret;
    return false;
}

int main() {
    ans = INF;
    cin >> A >> K;
    num = atoll(A.c_str());
    if (!rec(0, 0, false, false, 0)) {
        // 一桁減らしたやつ
        string prev = A;
        string next = "";
        for (int i = 0; i < A.size() - 1; i++) next += "9";
        A = next;
        rec(0, 0, false, false, 0);

        A = prev;
    }
    if (!rrec(0, 0, false, false, 0)) {
        // 一桁ふやしたやつ
        // 一桁減らしたやつ
        string prev = A;
        string next = "1";
        for (int i = 0; i < A.size(); i++) next += "0";
        A = next;
        rrec(0, 0, false, false, 0);
        A = prev;
    }

    cout << ans << endl;
}
