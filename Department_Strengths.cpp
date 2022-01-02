#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<bool> visited;
vector<vector<ll>> graph;
vector<ll> odd_roots;
vector<ll> even_roots;
ll Max;
ll Min;
ll Size;
ll temp;
ll oddAns, evenAns;

void dfs(ll parent){
    Size++;
    visited[parent]= true;
    Max= max(Max, parent);
    Min= min(Min, parent);
    for(int child: graph[parent])
        if(!visited[child])
            dfs(child);
}

void another(ll parent, ll level){
    visited[parent]= true;
    temp+=level;
    for(int child: graph[parent])
        if(!visited[child])
            another(child, level+1);
}


int main(){
    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        graph.clear();
        graph.resize(n+1);
        visited.clear();
        visited.resize(n+1);
        odd_roots.clear();
        odd_roots.resize(0);
        even_roots.clear();
        even_roots.resize(0);
        oddAns= evenAns= 0;
        for(int i=0; i<m; i++){
            ll x,y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for(int i=1; i<=n; i++)
            if(!visited[i]){
                Max= INT_MIN;
                Min= INT_MAX;
                Size= 0;
                dfs(i);
                if(Size%2==0)
                    even_roots.push_back(Min);
                else
                    odd_roots.push_back(Max);
            }
        visited.clear();
        visited.resize(n+1);
        for(int i: odd_roots){
            temp =0;
            another(i, 1);
            oddAns+=temp;
        }
        for(int i: even_roots){
            temp=0;
            another(i, 1);
            evenAns+=temp;
        }

        cout << evenAns << " " << oddAns << endl;
    }

    return 0;
}