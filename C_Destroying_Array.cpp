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
const int maxn = 200005;
int p[maxn];
ll sum[maxn], a[maxn];

struct dsu{
    vector<int> root, siz;
    dsu(int n) : root(n), siz(n,0){ iota(root.begin(), root.end(), 0);}
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
        sum[x] += sum[y];
        root[y] = x;
        return 1;
    }
    int size(int x) {return siz[findRoot(x)];}
    bool same(int x,int y){return (findRoot(x)==findRoot(y))? 1: 0;}
};

void solve(){
    ll n, curr = 0;
    cin >> n;
    dsu ds(n);
    fo(i,n){cin >> a[i];sum[i] = a[i];}
    fo(i,n){cin >> p[i];p[i]--;}
    vector<ll> ans;
    for(int i=n-1; i>=0; --i){
        ans.pb(curr);
        ds.siz[p[i]] = 1;
        if(p[i]>0 && (ds.size(p[i]-1)>0)){
            ds.unite(p[i], p[i]-1);
        }
        if(p[i]<n-1 && (ds.size(p[i]+1) > 0)){
            ds.unite(p[i], p[i]+1);
        }
        curr = max(curr, sum[ds.findRoot(p[i])]);
    }
    reverse(ans.begin(), ans.end());
    for(auto i: ans) cout << i << ln;
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