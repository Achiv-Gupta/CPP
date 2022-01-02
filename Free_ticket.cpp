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
const int maxn = 20000001;
// vector<vector<pair<int,int>>> adj;

void solve(){
    int n,m, tans = 0; 
    cin >> n >> m;
    int ans[n+1][n+1];
    fo(i,n+1) fo(j,n+1) ans[i][j] = maxn;
    // adj.resize(n+1);
    fo(i,m){
        int u,v,w;
        cin >> u >> v >> w;
        ans[u][v] = w;
        ans[v][u] = w;
    }
    for(int k = 1; k<=n; ++k){
        for(int i = 1; i<=n ; ++i){
            for(int j = 1; j<=n ; ++j){
                if(i == j) continue;
                ans[i][j] = min(ans[i][j], ans[i][k]+ans[k][j]);
            }
        }
    }
    for(int i = 1; i<=n ; ++i){
        for(int j = 1; j<=n ; ++j){
            if(ans[i][j] != maxn && ans[i][j] > tans){
                tans = ans[i][j];
                // cout << i << " " << j << ln;
            }
        }
    }
    cout << tans;
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