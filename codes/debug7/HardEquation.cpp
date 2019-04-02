
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int y;

int binary();
bool check(ll x);

int main() {
    cin >> y;
    cout << binary() << "\n";
    return 0;
}

int binary() {
    int lo = 1, hi = INT_MAX, mid, ans = 1;
    while (lo <= hi) {
        mid = (hi + lo) / 2;
        if (check(mid)) {
	cout<<"check(mid) :"<<check(mid);
            ans = mid;
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

bool check(ll x) {
    return (2 * x * x + 7 * x - 9 <= y);
}
