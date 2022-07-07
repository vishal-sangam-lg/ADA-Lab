#include<bits/stdc++.h>
using namespace std;
int lcs( string s1, string s2, int m, int n)
{
    int dp[m+1][n+1];
    fill(dp[0],dp[0]+(m+1)*(n+1),0);
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0){
                dp[i][j]=0;
            }

            else if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }

            else {
                dp[i][j]= max( dp[i-1][j] , dp[i][j-1]);
            }
        }
    }

    //  cout<<"The longest common subsequence is of length: "<<dp[m][n]<<endl;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[m][n];
    return dp[m][n];
}
int main(){
    string s1, s2;
    cout<<"Enter the strings s1 and s2:\n";
    cin>>s1>>s2;
    int res=lcs(s1, s2, s1.length(), s2.length());
    cout<<"The longest common subsequence is of length: "<<res;
    return 0;
}