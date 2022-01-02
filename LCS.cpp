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

void solve(){
    string s,t;
    cin >> s >> t;
    int n=s.size(), m=t.size(), ans = 0;
    int dp[n][m];
    fo(i,n){
        if(s[i] == t[0]){
            dp[i][0] = 1;
        }else{
            dp[i][0] = 0;
        }
    }
    fo(i,m){
        if(s[0] == t[i]){
            dp[0][i] = 1;
        }else{
            dp[0][i] = 0;
        }
    }
    for(int i = 1; i<n; ++i){
        for(int j = 1; j<m; ++j){
            if(s[i] == t[j]){
                dp[i][j] = 1+dp[i-1][j-1];
                ans = max(dp[i][j], ans);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    cout << ans;
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