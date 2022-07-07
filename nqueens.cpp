#include<bits/stdc++.h>
#define n 10
using namespace std;
bool board[n][n]={false};

bool isSafe(int row, int col)
{
    for(int i=0; i<col; i++)
    {
        if(board[row][i]==true)
        return false;
    }

    for(int i=row, j=col; i>=0 && j>=0 ; i--,j--)
    {
        if(board[i][j]==true)
        return false;
    }
    
    for(int i=row, j=col; i<n && j>=0; i++,j--)
    {
        if(board[i][j]==true)
        return false;
    }
    return true;
}

bool solveRec(int col)
{
    if(col== n)
    { return true; }
    for(int i=0; i<n; i++)
    {
        if(isSafe(i, col))
        {
            board[i][col]=1;
            if(solveRec(col+1))
            return true;
            board[i][col]=0;

        }
    }
    return false;
}

bool solve()
{
    if(solveRec(0)==false)
    return false;
    else{
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]==true)
                cout<<"Q ";
                else 
                cout<<"x ";
            }
            cout<<endl;
        }
        return true;
    }
}

int main()
{
    cout<<endl;
    solve();
    return 0;
}