#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int square(int n)
{
    if(n<0)
    {
        n=-n;
    }
    if(n==0)
    {
        return 0;
    }

    int x=n>>1;
    if(n&1)
    {
        return (square(x)<<2)+(x<<2)+1;
    }
    else
    {
        return square(x)<<2;
    }
}
int square2(int n)
{
    if(n<0)
    {
        n=-n;
    }
    int result=0,times=n;
    while(times>0)
    {
        int possibleShifts=0,curTimes=1;
        while((curTimes<<1)<=times)
        {
            curTimes<<=1;
            ++possibleShifts;
        }
        result+=(n<<possibleShifts);
        times-=curTimes;
    }
    return result;
}
int main() {
    int n;
    cin>>n;
    cout<<square2(n);
    return 0;
}
