#include <bits/stdc++.h>
using namespace std;
#define ll long long 
long long int mod=1e9+7;
long long int fastPower(long long int n,long long int p)
{
    if(p==0) return 1;
    
    
    long long int small=fastPower(n,p/2);
    small=(small*small)%mod;
    if(p&1)
    {
        return (small*n)%mod;
    }
    return small%mod;
    
}
long long int solve(long long int N, long long int A, long long int R,long long int p)
{
    if(N==0) return A;
    
    long long int num=solve(N-1,A,R,p-1);
    R=fastPower(R,N-1);
    R%=mod;
    num=(A*R)%mod;
    return num;
}
long long int nthTermOfGP(long long int N, long long int A,long long  int R) {
    return solve(N,A,R,N-1);
    
}


int main() {
   long long  int t;
    cin>>t;
    while(t--)
    {
    long long int a,r,n;
    cin>>n>>a>>r;
    cout<<nthTermOfGP(n,a,r)<<endl;
    }
    return 0;
}
