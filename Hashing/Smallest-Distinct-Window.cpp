// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string findSubString(string str)
    {
        // Your code goes here
        int n=str.size();
        if(n<=1)
        return str;
        int freq[256]={0};
        int min_len=INT_MAX,start_index=-1,start=0;
        int i=0;
         int dist_count = 0,count=0;
        bool visited[256] = { false };
        for (int i = 0; i < n; i++) {
            if (visited[str[i]] == false) {
                visited[str[i]] = true;
                dist_count++;
            }
        }
        while(i<n)
        {
            freq[str[i]]++;
            if(freq[str[i]]==1)
            count++;
            
            if(count==dist_count)
            {
                while(freq[str[start]]>1)
                {
                    if(freq[str[start]]>1)
                    freq[str[start]]--;
                    start++;
                }
            
                
                int len=i-start+1;
                if(min_len>len)
                {
                    min_len=len;
                    start_index=start;
                }
            }
            i++;
        }
        return str.substr(start_index,min_len);
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}  // } Driver Code Ends
