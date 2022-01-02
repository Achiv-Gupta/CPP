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
const int maxn = 505;
 
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
int n,m,k,s=0,smk;
bool vis[maxn][maxn]= {0};
pair<int, int> root = {0,0};
char matr[505][505] = {};

void find_s(int node1, int node2){
    vis[node1][node2] = 1;
    s++;
    if(matr[node1+1][node2] == '.' && !vis[node1+1][node2]) find_s(node1+1, node2);
    if(matr[node1-1][node2] == '.' && !vis[node1-1][node2]) find_s(node1-1, node2);
    if(matr[node1][node2+1] == '.' && !vis[node1][node2+1]) find_s(node1, node2+1);
    if(matr[node1][node2-1] == '.' && !vis[node1][node2-1]) find_s(node1, node2-1);
} 

void ans(int node1, int node2){
    vis[node1][node2] = 1;
    if(!smk) return;
    smk--;
    matr[node1][node2] = 'X';
    if(matr[node1+1][node2] == '.' && !vis[node1+1][node2]) ans(node1+1, node2);
    if(matr[node1-1][node2] == '.' && !vis[node1-1][node2]) ans(node1-1, node2);
    if(matr[node1][node2+1] == '.' && !vis[node1][node2+1]) ans(node1, node2+1);
    if(matr[node1][node2-1] == '.' && !vis[node1][node2-1]) ans(node1, node2-1);
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i<=n; ++i)
        for(int j = 1; j<=m; ++j){
            cin >> matr[i][j];
            if(!root.ff && matr[i][j] == '.') root = {i,j};
        }
    find_s(root.ff, root.ss);
    memset(vis,0,sizeof vis);
    smk = s-k;
    ans(root.ff , root.ss);
    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<=m; ++j){
            if(matr[i][j] == 'X')cout<<'.';
            else if(matr[i][j] == '.') cout << 'X';
            else cout << '#';
        }
        cout << ln;
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