#include<bits/stdc++.h>
using namespace std;
void lcs( string s1, string s2, int m, int n)
{
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0){
                dp[i][j]=0;
            }

            else if(s1[i]==s2[j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }

            else {
                dp[i][j]= max( dp[i-1][j] , dp[i][j-1]);
            }
        }
    }

     cout<<"The longest common subsequence is of length: "<<dp[m][n];

    // string ele="";
    // int cnt=0,i=m,j=n;
    // while(cnt!=dp[m][n] && i>=0 && j>=0)
    // {
    //     if(s1[i]==s2[j]){
    //     ele+=s1[i];
    //     i--;
    //     j--;
    //     cnt++;
    //     }
    //     else if(dp[i-1][j]>=dp[i][j-1]){
    //         i--;
    //     }
    //     //else j--;
    // }
      
    //  cout<<"\nThe selected elements are: "<<ele;
}
int main(){
    string s1, s2;
    cout<<"Enter the strings s1 and s2:\n";
    cin>>s1>>s2;
    lcs(s1, s2, s1.length(), s2.length());
    return 0;
}