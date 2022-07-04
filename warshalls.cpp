#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,e;
    cout<<"Enter the number of vertices:\n";
    cin>>n;
    int g[n][n];
    fill(g[0], g[0]+n*n, 0);
    cout<<"Enter the number of edges:\n";
    cin>>e;
    cout<<"Enter source and destination of the edges:\n";
    int a,b;
    for(int i=0; i<e; i++){
        cin>>a>>b;
        g[a][b]=1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    //Warshall's Algoithm

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n ;j++){
                g[i][j]= g[i][j] || (g[k][j]&&g[i][k]);
            }            
        }
    }

    cout<<endl<<endl;


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
