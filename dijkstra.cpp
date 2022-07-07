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
    int src;
    cout<<"Enter the source vertex\n";
    cin>>src;
    int dist[n];
    for(int i=0; i<n; i++){
        dist[i]=g[src][i];
    }
    dist[src]=0;
    bool mset[n]={false};
    int u=-1;
    for(int cnt=0; cnt<n; cnt++){
        for (int i = 0; i < n-1; i++)  //Changes
        {
            if(!mset[i] && (u=-1 || dist[i]<dist[u])){ 
                u=i;
            }
        }
        mset[u]=true;
        for(int i=0; i<n; i++){
            if(g[u][i]!=0 && !mset[i] && dist[u]!=999)  
            dist[i]=min(dist[i],dist[u]+g[u][i]);
        }
    }

    for(int i=0; i<n; i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}

