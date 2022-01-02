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
const int maxn = 105;
 
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
 
int n,m,q;
unordered_set<int> ans;
bool vis[maxn] = {0};
vector<pair<int,int>> adj[maxn];

void dfs(int node, int enode, int color = -1)
{
    if(node == enode)
    {
        ans.insert(color);
    }
    vis[node] = 1;
    for(auto i: adj[node])
    {
        if(!vis[i.ff] && (color == -1 || color == i.ss))
        {
            dfs(i.ff, enode, i.ss);
        }
    }
    vis[node] = false;
}

void solve(){
    cin >> n >> m;
    fo(i,m)
    {
        int t,tt,ttt;
        cin >> t >> tt >> ttt;
        adj[t].pb({tt,ttt});
        adj[tt].pb({t,ttt});
    }
    cin >> q;
    while(q--)
    {
        int t,tt;
        cin >> t >> tt;
        dfs(t,tt);
        cout << ans.size() << ln;
        ans.erase(ans.begin(), ans.end());
    }
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