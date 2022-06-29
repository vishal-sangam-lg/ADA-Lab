#include<bits/stdc++.h>
using namespace std;

int binomial(int n, int k)
{
    if(k>n)
    return 0;

    else if(k==0 || k==n)
    return 1;

    return binomial(n-1, k-1)+binomial(n-1, k);
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