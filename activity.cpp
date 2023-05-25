#include<bits/stdc++.h>
using namespace std;

int start[1000],finish[1000],l=0;
int flag[100]={0};
void exchange_finish(int x)
{
    int temp ;
    temp=finish[x+1];
    finish[x+1]=finish[x];
    finish[x]=temp;
}
void exchange_start(int x)
{
    int temp ;
    temp=start[x+1];
    start[x+1]=start[x];
    start[x]=temp;
}
void  bubble_sort(int n)
{
    int i,j,temp;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1;j++)
        {
            if(start[j]>start[j+1])
              {
                 exchange_start(j);
                 exchange_finish(j);
              }
        }

    }

}

void solve(int n)
{
    int array[n];
    array[0]=start[0];
    flag[0]=1;
    int k=0,l=0;

    for(int m=1; m<n; m++)
    {
        if(start[m] >= finish[k])
        {
           // cout<< "( "<<start[m] <<"," <<finish[m]<<")";
            array[++l]=start[m];
            flag[m]=1;
            k=m;
        }
    }
 // return array;
}
int main()
{
    int n,i,j;
    cout<<" Size of the array :"<<endl;
    cin >> n;

    cout<<"Input start & finish time:"<<endl;
    for(i=0; i<n; i++)
    {
      cin>>start[i]>>finish[i];
    }
    /*for(i=0; i<n;i++){
        cout<<start[i]<<" " ;
    }
    cout<<endl;
    for(i=0; i<n;i++){
        cout<<finish[i]<<" " ;
    }
    cout<<endl;*/
    bubble_sort(n);
   /*  for(i=0; i<n;i++){
        cout<<start[i]<<" " ;
    }
    cout<<endl;
    for(i=0; i<n;i++){
        cout<<finish[i]<<" " ;
    }
    cout<<endl;
*/
  solve(n);
  for(int i=0; i<n; i++)
  {
      if(flag[i]==1)
      {
          cout<< "(" <<start[i] <<"," << finish[i] <<")" ;
      }
  }
}

