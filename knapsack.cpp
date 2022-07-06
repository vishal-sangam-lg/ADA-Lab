#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int C, int n)
{
    int dp[n+1][C+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=C; j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(wt[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j] = max( dp[i-1][j], (val[i-1]+dp[i-1][j-wt[i-1]]));
            }
        }
    }

    //Table
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=C; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    //elements selected
    cout<<"The elements selected are: ";
    int j=C;
    for(int i=n; i>=1; i--)
    {
        if(dp[i-1][j]==dp[i][j])
            {
                i--;
            }
            else
            {
                cout<<i<<" ";
                j=j-wt[i];
            }
    }
    cout<<endl;

    return dp[n][C];
}

int main()
{
    int n;
    cout<<"Enter the number of elements\n";
    cin>>n;
    int wt[n], val[n], C;
    cout<<"Enter the weights and values of the elements in order\n";
    for(int i=0; i<n; i++)
    {
        cin>>wt[i]>>val[i];
    }
    cout<<"Enter the capacity\n";
    cin>>C;
    int res = knapsack(wt, val, C, n);
    cout<<"The max profit is:\n"<<res<<endl;
    return 0;
}