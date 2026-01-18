#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<int> d(n * 2);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        d[a] = i;
        d[b] = i;
    }

    stack<int> st;
    for (int x : d) {
        if (st.size() && st.top() == x) {
            st.pop();
        } else
            st.push(x);
    }

    if (st.size() == 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}
