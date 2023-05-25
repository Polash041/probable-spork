#include<bits/stdc++.h>
using namespace std;

vector<int> g[100];
vector<int> di(100,0);
vector<int>vis(100,0);
int parent[100];
void path_print(int st,int d)
{
    if(st == d) cout << st << " ";
    else if(parent[d]== 0){
        cout<< " No path";
    }
    else{
        path_print(st,parent[d]);
        cout<< d << " ";
    }
}
void bfs(int source)
{
    queue<int>q;
    q.push(source);
    di[source]=0;
    parent[source]=-1;
    vis[source]=1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<< u << " ";

        for(auto child : g[u])
        {
            if(!vis[child])
            {
                vis[child]=1;
                di[child]=di[u]+1;
                parent[child]=u;
                q.push(child);
            }
        }
    }
}
int main()
{
    int node,edge;
    cin>> node>> edge;

    for(int i=1; i<=edge; i++)
    {
        int x,y,wt;
        cin>>x>>y;
        //g[x].push_back({y,wt});
        //g[y].push_back({x,wt});
        g[x].push_back(y);
        g[y].push_back(x);
    }
   /* for(int i=1; i<=node; i++)
    {
     cout<< i <<"->";
     for(auto it : g[i])
     {
       cout<<"("<< it.first << ","<< it.second << ")";
     }
     cout << endl;
    }
    */
    for(int i=1; i<=node; i++)
    {
     cout<< i <<"->";
     for(auto it : g[i])
     {
       cout<< it << " ";
     }
     cout << endl;
    }
    int src;
    cin>>src;
    bfs(src);
    for(int i=1; i<=node; i++)
    {
        cout<<i<<"->"<< parent[i] << endl;;
    }
    int st,end;
    cin>>st>>end;
    path_print(st,end);
}
/*
10 9
1 8
1 5
1 2
8 6
8 4
8 3
2 9
6 10
6 7
*/
/*
5 6
1 2
1 3
1 4
3 4
3 5
4 5
*/
