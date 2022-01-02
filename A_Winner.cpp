#include<bits/stdc++.h>
using namespace std;
string x[1001];
map<string,int> m;
map<string,int> a;
int n,i,j,k[1001],ee=-1000000000;
int main(){
    cin>>n;
    for(i=1;i<=n;i++){
    	cin>>x[i]>>k[i];
    	m[x[i]]+=k[i];
    	a[x[i]]+=k[i];
	}
	for(i=1;i<=n;i++){
		ee=max(ee,m[x[i]]);
	    m[x[i]]=0;
	}
	for(i=1;i<=n;i++){
		m[x[i]]+=k[i];
		if(m[x[i]]>=ee&&a[x[i]]==ee) {cout<<x[i];return 0;}
	}
	return 0;
}