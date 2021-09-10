#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void subsetsString(string s,int i,string b)
{
    if(i==s.length())
    {
        cout<<b<<" ";
        return;
    }

    subsetsString(s,i+1,b);
    b.push_back(s[i]);
    subsetsString(s,i+1,b);


}
int main() {
    string s;
    cin>>s;
    string b="";
    subsetsString(s,0,b);
    return 0;
}
