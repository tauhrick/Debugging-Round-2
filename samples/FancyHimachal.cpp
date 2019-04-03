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
    cin >> m >> n >> d;
    ll u, v;
    fill(dis, dis + n, 0);
    for (ll i = 0; i < m; i++) {
        cin >> u >> v;
        rail[u].pb(v);
        vis[u][v] = true;
    }
    for (ll u = 1; u < n; u++) {
        for (ll v = u + 1; v <= n; v++) {
            if (!vis[u][v]) {
                road[u].pb({u - v, v});
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
    q.push({0,node});
    dis[node] = 0;
    ll w;
    while (!q.empty()) {
        node = q.top().second;
        q.pop();
        visited[node] = true;
        for (auto x : road[node]) {
            ll u = x.second;
            ll w = x.first;
            if (!visited[u]) {
                if (dis[node] + w <= dis[u]) {
                    dis[u] = dis[node] + w;
                    q.push({u, dis[u]});
                }
            }
        }
    }
}
