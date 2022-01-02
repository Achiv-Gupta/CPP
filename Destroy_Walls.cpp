#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
using namespace std;
 
typedef long long ll;
ll MOD = 998244353;
#define fo(i,e) for(ll i = 0; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 2e9
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int maxn = 100005;

struct dsu{
    vector<int> root, siz;
    dsu(int n) : root(n), siz(n,1){ iota(root.begin(), root.end(), 0);}
    int findRoot(int x){
        while(x != root[x]) x = root[x];
        return x;
    }
    bool unite(int x, int y){
        x = findRoot(x);
        y = findRoot(y);
        if(x==y) return 0;
        if(siz[x] < siz[y]) swap(x,y);
        siz[x] += siz[y];
        root[y] = x;
        return 1;
    }
};

void solve(){
    int n,m, ans = 0, weight = 0; cin >> n >> m;
    fo(i,n){int temp; cin >> temp >> temp;}
    vector<pair<int,pair<int,int>>> adj;
    fo(i,m){
        int u,v,w;
        cin >> u >> v >> w;
        adj.pb(mp(w,mp(u,v)));
    }
    dsu ds(n+1);
    sort(adj.begin(), adj.end(), greater<pair<int,pair<int,int>>>());
    for(auto i: adj){
        int u = i.ss.ff, v = i.ss.ss, w = i.ff;
        if(!ds.unite(u,v)){
            ans++;
            weight += w;
        }
    }
    cout << ans << " " << weight;
}

int main(){
    fast_cin();
    ll t=1;
    //cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}