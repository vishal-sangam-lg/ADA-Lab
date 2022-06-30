#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,e;
    cout<<"Enter the number of vertices:\n";
    cin>>n;
    int g[n][n];
    cout<<"Enter the number of edges:\n";
    cin>>e;
    cout<<"Enter source, destination and weight of the edges:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j)
            g[i][j]=0;
            else 
            g[i][j]=999;
        }
    }
    int a,b,c;
    for(int i=0; i<e; i++){
        cin>>a>>b>>c;
        g[a][b]=c;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //Floyd's Algoithm

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n ;j++){
                if(g[i][j]>(g[i][k]+g[k][j]) && g[i][k]!=999 && g[k][j]!=999)
                g[i][j]= g[i][k]+g[k][j];
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