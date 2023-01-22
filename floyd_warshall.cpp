#include<bits/stdc++.h>
using namespace std;
int parent[100][100];
void path_print(int st,int des)
{
    if(st == des) cout<< des << " ";
    else if(parent[des]==0) cout<<"No Path";
    else{
        path_print(st,parent[st][des]);
        cout<< des << " ";
    }
}
int main()
{
    int n,e;
    cin>>n>>e;

    int distance[100][100];

    for(int i=1; i<=n; i++)
    {
        for(int j=1;j<=n; j++)
        {
            parent[i][j]=0;
            //if(i==j)
            //    distance[i][j]=0;
            distance[i][j]=10000;
        }
    }
    for(int i=1; i<=n; i++){
        distance[i][i]=0;
    }
    for(int i=1; i<=e; i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        distance[x][y]=wt;
        parent[x][y]=x;
    }
    for(int k =1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(distance[i][j]> distance[i][k]+distance[k][j])
                {
                  distance[i][j]= distance[i][k]+distance[k][j];
                  parent[i][j]=parent[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<distance[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<"parent:";
     for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<parent[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<endl;
  cout<<"Path"<<endl;
  path_print(1,4);
}
/*
4 6
1 2 3
2 1 2
1 4 5
2 4 4
3 2 1
4 3 2

5 9
1 2 3
1 3 8
1 5 -4
5 4 6
2 5 7
2 4 1
4 1 2
4 3 -5
3 2 4
*/
