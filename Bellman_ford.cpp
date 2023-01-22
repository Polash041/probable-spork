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
    int src = 1;
    di[src]=0;
    for(int i=1; i<edge-1; i++)
    {
        for(auto edge : g[i])
        {
            int v = edge.first;
            int wt = edge.second;

            if(di[v] > di[i]+wt)
            {
                di[v]=di[i]+wt;
                parent[v]=i;
            }
        }
    }
    path_print(1,5);
}
