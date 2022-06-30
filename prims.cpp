// prim's algorithm

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of vertices\n";
    cin>>n;
    int g[n][n];
    cout<<"Enter the weights of edges from all sources to all destination\n";
    int a;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin>>a;
            g[i][j]=a;
            g[j][i]=a;
        }
    }
    
    int dist[n];
    for(int i=0; i<n; i++){
        dist[i]=g[0][i];
    }
    dist[0]=0;
    bool mset[n]={false};
    int u=-1,res=0;
    for(int cnt=0; cnt<n; cnt++){
        for (int i = 0; i < n; i++)
        {
            if(!mset[i] && (u=-1 || dist[i]<dist[u])){
                u=i;
            }
        }
        mset[u]=true;
        res=res+dist[u]; //  changed from dijkstra's
        for(int i=0; i<n; i++){
            if(g[u][i]!=0 && !mset[i])
            dist[i]=min(dist[i],g[u][i]);  //  changed from dijkstra's 
        }
    }
    
    cout<<"The weight of the minimum spanning tree is: "<<res;
    return 0;
}
