#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,t,f[100010],p;
bool a[100010];
inline int fa(int i)
{
    return f[i]==i?i:f[i]=fa(f[i]);
}
struct edge
{
    int u,v,w;
    inline void unit()
    {
        u=fa(u);
        v=fa(v);
        if(u!=v)
          {
           if(a[u])
             f[v]=u;
           else
             f[u]=v;
           if(a[u] && a[v])
             p--;
           if(p==1)
             {
              for(int i=1;i<=t;i++)
                printf("%d ",w);
              printf("\n");
              exit(0);
             }
          }
    }
}x[100010];
inline bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
int main()
{
    int i,j;
    scanf("%d%d%d",&n,&m,&t);
    p=t;
    for(i=1;i<=t;i++)
      {
       scanf("%d",&j);
       a[j]=1;
      }
    for(i=1;i<=m;i++)
      scanf("%d%d%d",&x[i].u,&x[i].v,&x[i].w);
    sort(x+1,x+m+1,cmp);
    for(i=1;i<=n;i++)
      f[i]=i;
    for(i=1;i<=m;i++)
      x[i].unit();
    return 0;
}