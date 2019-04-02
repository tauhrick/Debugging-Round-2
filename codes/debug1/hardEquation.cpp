#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll y;

int binary();
bool check(int x);

int main() {
    cin >> y;
    cout << binary() << "\n";
    return 0;
}

int binary() {
    int lo = 0, hi = INT_MAX, mid, ans=1;
    while (lo < hi) {
        mid = lo + (hi - lo + 1) / 2;
        if (check(ll(mid))) {
            ans = mid;
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

bool check(int x) {
    return (2 * x * x + 7 * x - 9 <= y);
}
