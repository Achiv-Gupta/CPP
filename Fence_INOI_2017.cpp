#include<bits/stdc++.h>
using namespace std;
vector<bool> visited(100001);
vector<vector<int>> adj(100001);
map<pair<int,int>, long long> mat;
int length;
bool valid(int i, int j, int r, int c){
	return i > 0 && i <= r && j > 0 && j <= c;
}

void dfs(int node){
    length = length + 4 - adj[node].size();
    visited[node] = 1;
    for(auto i: adj[node]){
        if(!visited[i]) dfs(i);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int r,c,n,ans = 0;
	cin >> r >> c >> n;
	for (int i = 1; i <= n; i++){
		int a,b;
		cin >> a >> b;
		mat[{a,b}] = i;
		if (valid(a-1,b,r,c) && mat[{a-1,b}]){
			adj[i].push_back(mat[{a-1,b}]);
			adj[mat[{a-1,b}]].push_back(i);
		}
		if (valid(a,b-1,r,c) && mat[{a,b-1}]){
			adj[i].push_back(mat[{a,b-1}]);
			adj[mat[{a,b-1}]].push_back(i);
		}
		if (valid(a+1,b,r,c) && mat[{a+1,b}]){
			adj[i].push_back(mat[{a+1,b}]);
			adj[mat[{a+1,b}]].push_back(i);
		}
		if (valid(a,b+1,r,c) && mat[{a,b+1}]){
			adj[i].push_back(mat[{a,b+1}]);
			adj[mat[{a,b+1}]].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++){
		if(visited[i]){continue;}
        length = 0;
		dfs(i);
		ans = max(ans,length);
	}
	cout << ans;
	return 0;
}