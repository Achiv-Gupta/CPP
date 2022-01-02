#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
const int maxn = 1005;
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vv64;
typedef vector<vector<pll> > vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 998244353;
double eps = 1e-12;
#define fo(i,e) for(ll i = 0; i < e; i++)
#define fos(i,s,e) for(ll i = s; i < e; i++)
#define rfo(i,s) for(ll i = s; i >= 0; i--)
#define rfos(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
int n,m,s,t,ans=0;
vector<int> adj[maxn], ds(maxn, -1), dt(maxn,-1);

void bfst(){
    queue<int> q;
    q.push(t);
    dt[t] = 0;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto i: adj[node]){
            if(dt[i] == -1)
            {
                q.push(i);
                dt[i] = dt[node]+1;
            }
        }
    }
}

void bfss(){
    queue<int> q;
    q.push(s);
    ds[s] = 0;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto i: adj[node]){
            if(ds[i] == -1)
            {
                q.push(i);
                ds[i] = ds[node]+1;
            }
        }
    }
}

void solve(){
    cin >> n >> m >> s >> t;
    fo(i,m){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bfst();
    bfss();
    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<=n; ++j){
            if(i==j) continue;
            vector<int>::iterator it = std::find (adj[i].begin(), adj[i].end(), j);
            if (it != adj[i].end()) continue; 
            if((ds[i]+dt[j]+1) < ds[t]) continue;
            if((dt[i]+ds[j]+1) < ds[t]) continue;
            ans++;
        }
    }
    // dbg(ds[t]);
    cout << ans/2;
}

int main()
{
    fast_cin();
    ll t=1;
    // cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}