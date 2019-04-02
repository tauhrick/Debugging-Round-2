#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll y;

int binary();
bool check(ll x);

int main() {
    cin >> y;
    cout << binary() << "\n";
    return 0;
}

int binary() {
    ll lo = 1, hi = INT_MAX, mid, ans = 1;
    while (lo <= hi) {
        mid = (hi + lo) / 2;
        if (check(mid)) {
            ans = mid;
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    return ans;
}

bool check(ll x) {
    return (2 * x * x + 7 * x - 9 <= y);
}
