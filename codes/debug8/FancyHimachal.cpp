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
bool vis[N][N], visited[N];
ll dis[N];

void functionn(ll node);

int main() {
    ll n, m, d;
    cin >> n >> m >> d;
    ll u, v;
    fill(dis, dis + n+1, inf);
    for (ll i = 0; i < m; i++) {
        cin >> u >> v;
        rail[u].pb(v);
        vis[u][v] = true;
        vis[v][u] = true;
    }
    for (ll u = 1; u <= n; u++) {
        for (ll v = 1; v <= n; v++) {
            if (!vis[u][v] and u!=v) {
                road[u].pb(v);
            }
        }
    }
    functionn(1LL);
    if (dis[d] == inf) {
        cout << -1 << "\n";
    } else {
        cout << dis[d] << "\n";
    }
    return 0;
}

void functionn(ll node) {
    priority_queue < pll > q;
    q.push({0,node});
    dis[node] = 0;
    while (!q.empty()) {
        node = q.top().second;
        q.pop();
        //visited[node] = true;
        for (auto x : road[node]) {
            if (!visited[x]) {
            ll w= abs(node-x);
                if (dis[node] + w <= dis[x]) {
                    dis[x] = dis[node] + w;
                    q.push({0, x});
                }
            }
        }
    }
}
