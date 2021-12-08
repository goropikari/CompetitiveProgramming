#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

#define rep(i,n) for (ll i = 0; i < (n); i++)

int main(int argc, char* argv[])
{
    ll n;
    cin >> n;

    ll sqr = sqrt(n);
    ll ans = 0;
    for (ll i = 1; i <= sqr; i++) {
        ans += n / i;
    }
    ans *= 2;
    ans -= sqr * sqr;
    cout << ans << endl;

    return 0;
}
