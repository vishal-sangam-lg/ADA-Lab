#include<bits/stdc++.h>
using namespace std;
int lcs( string s1, string s2, int m, int n)
{
    int dp[m+1][n+1];
    bool arr[m]= {false};
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0){
                dp[i][j]=0;
                if(s1[i]==s2[j])
                arr[i]=true;
            }

            else if(s1[i]==s2[j]){
                dp[i][j] = 1 + dp[i-1][j-1];
                arr[i]=true;
            }

            else {
                dp[i][j]= max( dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    
    for(int i=0; i<m; i++)
    {
        if(arr[i]==true)
        {
            cout<<s1[i]<<" ";
        }
    }
    return dp[m][n];

}
int main(){
    string s1, s2;
    cout<<"Enter the strings s1 and s2:\n";
    cin>>s1>>s2;
    int res = lcs(s1, s2, s1.length(), s2.length());
    cout<<"The longest common subsequence is of length: "<<res;
    return 0;
}
