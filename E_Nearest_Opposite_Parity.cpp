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


void solve(){
    int n; cin >> n;
    int arr[n+1], ans[n+1];
    fill(ans, ans+n+1, -1);
    // cout << ans[5] << ln;
    vi adj[n+1];
    vi vise(n+1, -1), viso(n+1,-1);
    queue<int> even, odd;
    for(int i = 1; i<=n ; ++i){
        cin >> arr[i];
        if(arr[i]&1) {odd.push(i);viso[i] = 0;}
        else {even.push(i);vise[i]=0;}
    }
    for(int i = 1; i<=n ; ++i){
        if((i+arr[i])<=n) adj[(i+arr[i])].pb(i);
        if((i-arr[i])>=1) adj[(i-arr[i])].pb(i);
    }
    while(!even.empty()){
        int temp = even.front(); even.pop();
        for(auto i: adj[temp]){
            if(vise[i] != -1) continue;
            even.push(i); 
            vise[i] = vise[temp]+1;
            if(arr[i]&1) ans[i] = vise[i];
        }
    }
    while(!odd.empty()){
        int temp = odd.front(); odd.pop();
        for(auto i: adj[temp]){
            if(viso[i] != -1) continue;
            odd.push(i);
            viso[i] = viso[temp]+1;
            // if(i == 1) dbg(temp);
            if(!(arr[i]&1)) ans[i] = viso[i];   
        }
    }
    for(int i =1 ; i<=n ; ++i){
        cout << ans[i] << " ";
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