#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt = 0;
const int maxn = 505;
ll a[maxn], b[maxn], dp[maxn];
int pre[maxn], ans[maxn]; int pos, maxx;
int main(){
    int an, bn;
    cin>>an;
    for (int i=1; i<=an; i++){
        cin>>a[i];
    }
    cin>>bn;
    for (int i=1; i<=bn; i++){
        cin>>b[i];
    }
    memset(dp, 0, sizeof (dp));
    memset(pre, -1, sizeof(pre));
    for (int i=1; i<=an; i++){ 
        pos = 0;
        for (int j=1; j<=bn; j++){
            if (a[i] == b[j]) dp[j] = dp[pos] +1, pre[j] = pos;
            if (b[j] <a[i] && dp[pos] <dp[j])
                pos = j;
        }
    }
    maxx = -1;
    for (int i=1; i<=bn; i++){
        if (maxx <dp[i]) {
            maxx = dp[i];
            pos = i;
        }
    }

    for (int i=maxx; i; i--){
        ans[i] = b[pos];
        pos = pre[pos];
    }
    cout<<maxx<<endl;
    for (int i=1; i<=maxx; i++){
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}