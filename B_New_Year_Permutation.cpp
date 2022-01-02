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
const int maxn = 305;
int n, arr[maxn], tans[maxn];
bool vis[maxn] = {0};
vector<int> adj[maxn], ans, anss;

void dfs(int node){
    ans.pb(node);
    anss.pb(arr[node]);
    vis[node] = 1;
    for(auto i: adj[node]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void solve(){
    cin >> n;
    fo(i,n) cin >> arr[i];
    fo(i,n){
        string s;
        cin >> s;
        fo(j,n){
            if(i == j) continue;
            if(s[j] == '1'){
                adj[i].pb(j);
                // cout << i << " " << j << ln ;
            }
        }
    }
    fo(i,n){
        ans.clear(); 
        anss.clear();
        if(!vis[i]){
            dfs(i);
            sort(ans.begin(), ans.end());
            sort(anss.begin(), anss.end());
            for(int j = 0 ; j<ans.size(); ++j){
                arr[ans[j]] = anss[j];
            }
        }
    }
    fo(i,n) cout << arr[i] << " ";
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