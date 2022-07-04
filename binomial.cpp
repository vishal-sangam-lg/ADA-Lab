#include<bits/stdc++.h>
using namespace std;

int binomial(int n, int k)
{
    int dp[n+1][k+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            if(j>i)
            {
                dp[i][j]=0;
            }
            else if(j==0 || j==n)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
    return dp[n][k];
}

int main()
{
    int n=0, k=0; 
    cout<<"Enter the n and k values:\n";
    cin>>n>>k;
    int res= binomial(n, k);
    cout<<"The result is: "<<res;
    return 0;
}
