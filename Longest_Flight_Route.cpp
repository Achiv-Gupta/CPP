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
int n,m,ans = 0;
vector<vector<int>> adj, radj;
vector<int> dp(maxn, 0), par(maxn, 0), vans;
stack<int> st;

void dfs(int node){
    for(auto i: adj[node]){
        if(dp[i] == 0){
            dp[i] = dp[node]+1;
            par[i] = node;
            dfs(i);
        }
    }
    st.push(node);
}

void solve(){
    cin >> n >> m;
    adj.resize(n+1);
    radj.resize(n+1);
    fo(i,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        radj[v].pb(u);
    }
    dp[1] = 1;
    dfs(1);
    if(dp[n] == 0){
        cout << "IMPOSSIBLE";
        return;
    }
    while(!st.empty()){
        int curr = st.top();st.pop();
        for(auto i : radj[curr]){
            if(dp[curr] < dp[i]+1){
                dp[curr] = dp[i]+1;
                par[curr] = i;
            }
        }
    }
    while(n != 0){
        vans.pb(n);
        n = par[n];
    }
    reverse(vans.begin(), vans.end());
    cout << vans.size() << ln;
    for(auto i: vans) cout << i << " ";
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