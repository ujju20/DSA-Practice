#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void permutations(string s,int l,int r)
{
    if(l==r)
    {
        cout<<s<<" ";
        return;
    }

    for(int i=l;i<=r;i++)
    {
        swap(s[l],s[i]);
        permutations(s,l+1,r);
        swap(s[l],s[i]);
    }
}
int main() {
    string s;
    cin>>s;
    permutations(s,0,s.length()-1);
    return 0;
}


//We can use next_permutation that modifies a string so that it stores lexicographically next permutation.
//If current string is lexicographically largest, i.e., “CBA”, then next_permutation returns false.

//We first sort the string, so that it is converted to lexicographically smallest permutation.
//Then we one by one call next_permutation until it returns false.

