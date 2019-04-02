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
   long long int lo = 1, hi = y, mid, ans = 1;
    while (lo <= hi) 
	{
        mid = (hi + lo) / 2;
        if (check(ll(mid))) {
            ans = mid;
            lo = mid+1;
        } else {
            hi = mid-1;
            ans=mid;
        }
    }
    return ans;
}

bool check(int x) {
    return ((2 * x * x + 7 * x - 9) <= y);
}
