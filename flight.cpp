//
// Created by zsr on 2022/6/5.
//

#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=2e5+5;
const int INF=0x7fffffff;
typedef long long ll;
int head[MAXN],tot,s,t;
struct node
{
    int to,nxt,flow;
}e[MAXN];
void add(int x,int y,int z)
{
    e[tot].to=y;e[tot].flow=z;e[tot].nxt=head[x];head[x]=tot++;
}
void add_edge(int x,int y,int z)
{
    add(x,y,z);add(y,x,0);
}
int dep[MAXN],l,r,q[MAXN];
bool bfs()
{
    memset(dep,0,sizeof(dep));
    l=0,r=0;
    q[++r]=s;dep[s]=1;
    while(l!=r)
    {
        int u=q[++l];
        for(int i=head[u];~i;i=e[i].nxt)
        {
            int v=e[i].to;
            if(!dep[v]&&e[i].flow)
            {
                dep[v]=dep[u]+1;
                q[++r]=v;
            }
        }
    }
    return dep[t];
}
int dfs(int u,int min_f)
{
    if(u==t)
        return min_f;
    int temp_f=0;
    for(int i=head[u];~i&&min_f;i=e[i].nxt)
    {
        int v=e[i].to;
        if(dep[v]==dep[u]+1&&e[i].flow)
        {
            int d=dfs(v,min(min_f,e[i].flow));
            if(d>0)
            {
                min_f-=d;
                temp_f+=d;
                e[i].flow-=d;
                e[i^1].flow+=d;
            }
        }
    }
    if(!temp_f)dep[u]=-1;
    return temp_f;
}
int dinic()
{
    int  res=0;
    while(bfs())
        res+=dfs(s,INF);
    return res;
}
int main()
{
    int n,m;
    cin>>n>>m;
    s=0,t=n+1;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++)
        add_edge(s,i,1);
    for(int i=m+1;i<=n;i++)
        add_edge(i,t,1);
    int x,y;
    while(!cin.eof())
    {
        cin>>x>>y;
        add_edge(x,y,1);
    }
    int ans=dinic();
    cout<<ans<<endl;
    return 0;
}