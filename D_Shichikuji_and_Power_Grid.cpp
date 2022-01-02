#include <bits/stdc++.h>
#define x first
#define y second
typedef long long ll;
using namespace std;


struct UFDS {
    vector <int> link, siz;
    UFDS(int n): link(n), siz(n, 1) {
        for (int i = 0; i < n; i++) link[i] = i;
    }
    int findRoot(int x) {
        return x == link[x] ? x : link[x] = findRoot(link[x]);
    }
    bool same(int x, int y) {
        return findRoot(x) == findRoot(y);
    }
    bool unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y)
            return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        link[y] = x;
        return true;
    }
    int size(int x) {
        return siz[findRoot(x)];
    }
};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<pair<ll, ll>> coords(n);
    vector<ll> buildCost(n), edgeCost(n);

    for(auto & c: coords)
        cin >> c.x >> c.y;
    for(auto & v: buildCost)
        cin >> v;
    for(auto & v: edgeCost)
        cin >> v;

    vector<pair<ll,pair<int, int>>> edges;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            pair <ll, ll> a = coords[i], b = coords[j];
            ll cost = (edgeCost[i] + edgeCost[j]) * ll(abs(a.x - b.x) + abs(a.y - b.y));
            edges.push_back({cost,{i + 1,j + 1}});
        }
        edges.push_back({buildCost[i],{0,i + 1}});
    }

    UFDS ds(n + 1);
    sort(edges.begin(), edges.end());

    ll ans = 0;
    vector<int> stations;
    vector<pair<int, int>> built;

    for(auto & e: edges) {
        if(ds.unite(e.y.x, e.y.y)) {
            ans += e.x;
            if(e.y.x == 0) {
                stations.push_back(e.y.y);
            } 
            else {
                built.push_back(e.y);
            }
        }
    }

    cout << ans << '\n';

    cout << (int) stations.size() << '\n';
    for (auto & s: stations)
        cout << s << ' ';
    cout << '\n';

    cout << (int) built.size() << '\n';
    for (auto & s: built)
        cout << s.x << ' ' << s.y << '\n';
}
