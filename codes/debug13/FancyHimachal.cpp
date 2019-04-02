#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair < ll, ll > pll;
typedef vector < ll > vll;

#define pb push_back

const ll inf = INT_MAX;
const ll N = 1e3 + 10;

vll rail[N];
vector<pll> road[N];
bool vis[N][N], visited[N];
ll dis[N];

void function1(ll node);

struct Func {
	bool operator()(const pll a, const pll b) { return a.first > b.first;}
};

int main() {
    ll n, m, d;
    cin >> n >> m >> d;
    ll u, v;
    fill(dis, dis + n+3, inf);
    for (ll i = 0; i < m; i++) {
        cin >> u >> v;
        rail[u].pb(v);
        rail[v].pb(u);
        vis[u][v] = true;
        vis[v][u] = true;
    }
    for (ll u = 1; u < n; u++) {
        for (ll v = u + 1; v <= n; v++) {
            if (!vis[u][v]) {
                road[u].pb({v-u, v});
                road[v].pb({v-u, u});
            }
        }
    }
    function1(1);
    if (dis[d] == inf) {
        cout << -1 << "\n";
    } else {
        cout << dis[d] << "\n";
    }
    return 0;
}

void function1(ll node) {
    priority_queue < pll ,vector<pll> ,Func > q;
    q.push({0,node});
    dis[node] = 0;
    visited[node] = true;
    while (!q.empty()) {
        node = q.top().second;
        q.pop();
        for (auto x : road[node]) {
            ll u = x.second;
            ll w = x.first;
            if (!visited[u]) {
                if (dis[node] + w <= dis[u]) {
                    dis[u] = dis[node] + w;
                    q.push({dis[u], u});
                }
		    visited[u]=true;
            }
        }
    }
}
