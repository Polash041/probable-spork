#include<bits/stdc++.h>
using namespace std;
vector<int>g[100];
vector<int>vis(100,0);
vector<int>di(100,0);
int parent[100];
void dfs_vis(int u)
{
    vis[u]=1;
    cout<< u << " ";
    for(auto it : g[u])
    {
        if(!vis[it])
        {
        vis[it]=1;
        parent[it]=u;
        dfs_vis(it);
        }
    }
}
/*void dfs(int node)
{
  for(int i=1; i<=node; i++)
  {
      for(auto it : g[i])
      {
          if(!vis[it])
          {
           dfs_vis(it);
          }
      }
  }
}
*/
int main()
{
    int node,edge;
    cin>> node>> edge;


    for(int i=1; i<=edge; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs_vis(1);
}
/*
8 10
1 2
1 3
1 4
1 5
2 6
3 6
4 7
5 7
6 8
7 8
*/
