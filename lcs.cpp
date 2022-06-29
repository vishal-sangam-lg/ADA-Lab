#include<bits/stdc++.h>
using namespace std;
int lcs( string s1, string s2, int m, int n)
{
    int dp[m][n];
    if(m==0 || n==0){
        dp[m][n]=0;
    }

    else if(s1[m]==s2[n]){
        dp[m][n] = 1 + lcs(s1,s2,m-1,n-1);
    }

    else {
        dp[m][n]= max( lcs(s1,s2,m-1,n) , lcs(s1,s2,m,n-1));
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