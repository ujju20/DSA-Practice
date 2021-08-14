#include <bits/stdc++.h>
using namespace std;
#define ll long long 
long long int divideIntegers(long int dividend,long int divisor)
{
     int sign = ((dividend < 0) ^
              (divisor < 0)) ? -1 : 1;
    divisor=abs(divisor);
    dividend=abs(dividend);
    int temp=0;
    long long int quotient=0;
    for(int i=31;i>=0;--i)
    {
        if(temp+(divisor<<i)<=dividend)
        {
            temp+=divisor<<i;
            quotient|=1LL<<i;
        }
    }
    if(sign==-1) quotient=-quotient;
    return quotient;
}
int main() {
    long long int n,m;
    cin>>n>>m;
    cout<<divideIntegers(n,m);
    return 0;
}
