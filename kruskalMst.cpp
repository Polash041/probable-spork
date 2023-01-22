#include<bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int>>> edges;
int parent[100]={0};
//make->
void make(int v)
{
    parent[v]=v;
}

//Godfather finding
int find(int v)
{
    if(parent[v]==v) return parent[v];
    return(find(parent[v]));
}

void uni(int a,int b)
{
    a = find(a);
    b = find(b);

    if(a != b)
      parent[b]=a;
}

int main()
{
    int node,edge;
    cin>>node>>edge;

    for(int i=0; i<edge; i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;

        edges.push_back({wt,{x,y}});
        //edges.push_back({wt,{y,x}});
    }
    int ans=0;
    //4
    sort(edges.begin(),edges.end());
    //2 & 3
    for(int i=0; i<node; i++)
    {
        make(i);
    }
    for(auto edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if(find(u) == find(v)) continue;
            uni(u,v);
            ans+=wt;
            cout<<u << " "<< v << endl;
    }
    cout<< ans;
}
/*9 14
0 1 4
0 7 8
1 7 11
1 2 8
7 6 1
7 8 7
2 8 2
8 6 6
2 5 4
2 3 7
6 5 2
3 4 9
3 5 14
5 4 10
*/
/*6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7
*/
