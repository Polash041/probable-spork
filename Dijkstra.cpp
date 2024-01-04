#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[100];
vector<int>di(100,INT_MAX);
vector<int>vis(100,0);
vector<int>parent(100,INT_MAX);
void path_print(int st,int des)
{
    if(st == des) cout<< des << " ";
    else if(parent[des]==0) cout<<"No Path";
    else{
        path_print(st,parent[des]);
        cout<< des << " ";
    }
}
void Dijkstra(int source)
{
    set<pair<int,int>>st;
    st.insert({0,source});
    di[source]=0;
    parent[source]=0;

    while(st.size()>0)
    {
        auto node = *st.begin();
        int d = node.first;
        int u = node.second;
        st.erase(st.begin());
        if(vis[u]) continue;
        vis[u]=1;
        //st.erase(st.begin());
        for(auto child : g[u])
        {
            int v= child.first;
            int wt = child.second;

            if(di[u]+wt < di[v])
            {
                parent[v]=u;
                di[v]=di[u]+wt;
                st.insert({di[v],v});

            }
        }
    }
}
int main()
{
    int node,edge;
    cin>>node>>edge;

    for(int i=1; i<=edge; i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;

        g[x].push_back({y,wt});
        g[y].push_back({x,wt});
    }
    Dijkstra(1);
    path_print(1,5);
}
/*
6 9
1 2 1
1 3 5
2 3 2
3 5 2
2 5 1
2 4 2
4 5 3
4 6 1
5 6 2
*/
