#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter the number of vetices and edges\n";
    int n, e;
    cin>>n>>e;
    int g[n][n];
    cout<<"Enter the edges\n";
    fill(g[0], g[0]+n*n, 0);
    for(int i=0; i<e; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a][b]=1;
    }

    int indeg[n];
    for(int i=0; i<n; i++){
        indeg[i]=0;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            indeg[j]=indeg[j]+g[i][j]; 
        }
    }
    
    queue <int> q;
    for(int i=0; i<n; i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
            indeg[i]=-1;
        }
    }
    int cnt=n;
    while( cnt!=0 ){
        int u=q.front();
        cout<<q.front();
        q.pop();
        cout<<" ";
        for(int i=0; i<n; i++)
        {
            if(g[u][i]!=0)
            {
                indeg[i]--;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
                indeg[i]=-1;
            }
        }
        cnt--;
    }
    return 0;
}