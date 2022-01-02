#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
      
const int N = 1000010, M = 2000010;
int n, m, k;
struct edge {
    int u, v;
} edges[M];
int vis[M];
vector<pair<int, int>> ans;

struct UFDS {
    vector<int> link, siz;
    UFDS(int n) : link(n), siz(n, 1) { iota(link.begin(), link.end(), 0); }
    int findRoot(int x) {
        if(x == link[x]) return x;
        return link[x] = findRoot(link[x]);
    }
    bool same(int x, int y) { return findRoot(x) == findRoot(y); }
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
    int size(int x) { return siz[findRoot(x)]; }
};

UFDS ds(N);
        
int main() {
  cin.tie(0); cout.tie(0);
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;

  for(int i = 1; i <= m; ++i) {
    cin >> edges[i].u >> edges[i].v;
                                   
    if(edges[i].u > k && edges[i].v > k)
      ds.unite(edges[i].u, edges[i].v), vis[i] = 1; //combine all the allowed cities
  }

  for(int i = 1; i <= m; ++i)
    if(ds.findRoot(edges[i].u) != ds.findRoot(edges[i].v)) //combine if a cycle is not formed(can you figure out how this condition ensures a cycle is not formed?)
      ds.unite(edges[i].u, edges[i].v), vis[i] = 1;

  for(int i = 1; i <= m; ++i)
    if(!vis[i]) //this is our answer, all the un-connected edges
      ans.emplace_back(make_pair(edges[i].u, edges[i].v));

  cout << (int)ans.size() << '\n';

  for(auto i: ans)
    cout << i.first << ' ' << i.second << '\n';

  return 0;
}
