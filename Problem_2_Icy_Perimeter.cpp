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
const int maxn = 100005;
 
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
int ans = 0, peri = 0, tans = 0, tperi = 0;
char grid[1005][1005];
bool vis[1005][1005] = {0};

void usaco(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

void dfs(int i , int j){
    tans++;
    vis[i][j] = 1;
    if(grid[i+1][j] == '#' && !vis[i+1][j]) dfs(i+1,j); 
    if(grid[i+1][j] == '.') tperi++;
    if(grid[i-1][j] == '#' && !vis[i-1][j]) dfs(i-1,j);
    if(grid[i-1][j] == '.') tperi++;
    if(grid[i][j+1] == '#' && !vis[i][j+1]) dfs(i,j+1);
    if(grid[i][j+1] == '.') tperi++;
    if(grid[i][j-1] == '#' && !vis[i][j-1]) dfs(i,j-1);
    if(grid[i][j-1] == '.') tperi++;
}

void solve(){
    int n; cin >> n ;
    fo(i,n+2){
        fo(j,n+2){
            vis[i][j] = 0;
            if(i == n+1 || j == n+1 || j == 0 || i == 0){
                grid[i][j] = '.';
                continue;
            }
            cin >> grid[i][j];
        }
    }
    fo(i,n+2){
        fo(j,n+2){
            if((!vis[i][j]) && (grid[i][j] == '#')) dfs(i,j);
            if(ans<tans){
                ans = tans;
                peri = tperi;
            }
            else if(ans == tans){
                peri = min(peri, tperi);
            }
            tans = 0, tperi = 0;
        }
    }
    cout << ans << " " << peri;
}

int main()
{
    usaco("perimeter");
    fast_cin();
    ll t=1;
    // cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}