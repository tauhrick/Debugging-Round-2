
//fancy himachal

//namisha goyal, 17mi550, 8847615253
//parul, 17mi559, 8352065425 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair < ll, ll > pll;
typedef vector < ll > vll;

#define pb push_back

const ll inf = LLONG_MAX;
const ll N = 1e3 + 10;

vll rail[N];
vll road[N];
bool vis[N], visited[N];
ll dis[N];

void function(ll node);

int main() {
    ll n, m, d;
    cin >> n >> m >> d;
    ll u, v;
    fill(dis, dis + n, inf);
    for (ll i = 0; i < m; i++) {
        cin >> u >> v;
        rail[u].pb(v);
	vis[v] = true;
        vis[u] = true;
    }
    for (ll u = 1; u < n; u++) {
        for (ll v = u + 1; v <= n; v++) {
            if (!vis[u] || !vis[v]) {
                road[u].pb(v);
		road[v].pb(u);
            }
        }
    }
    function(1);
    if (dis[d] == inf) {
        cout << -1 << "\n";
    } else {
        cout << dis[d] << "\n";
    }
    return 0;
}

void function(ll node) {
    priority_queue < pll > q;
    q.push(make_pair(0,node));
    dis[node] = 0;
    ll w;
    while (!q.empty()) {
        node = q.top().second;
        q.pop();
	if (visited[node] != true) {
        visited[node] = true;
        for (ll x = 0; x < road[node].size(); x++) {
		if (visited[road[node][x]] != true) {
            ll u = road[node][x];
            ll w = abs(u - node);
                if (dis[node] + w <= dis[u]) {
                    dis[u] = dis[node] + w;
			q.push(make_pair(dis[u], u));
                }
		}
        }
	}
    }
}
