#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<assert.h>
#define int long long
using namespace std;
int m=1000000007;
int fact[10001], invfact[10001];

int pow(int a, int e)
{
    if(e==1)
        return a;
    int t=pow(a,e/2);
    t=(t*t)%m;
    if(e&1)
    {
        t=(t*a)%m;
    }
    return t;
}

int C(int n, int k)
{
    if(n<k)
        return 0;
    if(k==0 || k==n)
        return 1;
    int c=(fact[n]*invfact[k])%m;
    c=(c*invfact[n-k])%m;
    return c;
}

int32_t main() 
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    
    fact[0]=1;
    for(int i=1; i<=10000; ++i)
        fact[i]=(i*fact[i-1])%m;
    invfact[0]=1, invfact[1]=1;
    for(int i=2; i<=10000; ++i)
    {
        invfact[i]=pow(fact[i],m-2);
    }
    
    int n, q;
    cin>>n>>q;
    
    int outdeg[n]={}, e;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cin>>e;
            if(e>1) e=1;
            outdeg[i]+=(e&(i!=j));
        }
    }
    sort(outdeg, outdeg+n);
    
    int dp[10001]={};
    for(int k=0; k<=n; ++k)
    {
        for(int i=n-1; i>=0; --i)
        {
            if(outdeg[i]<k)
                break;
            dp[k]=(dp[k]+C(outdeg[i],k))%m;
        }
    }
    
    while(q--)
    {
        int k;
        cin>>k;
        if(k>n)
        {
            cout<<0<<endl;
            continue;
        }
        cout<<dp[k]<<endl;
    }
    
    return 0;
}