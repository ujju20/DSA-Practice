// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    int n=(1<<s.length())-1;
		    for(int i=1;i<=n;i++)
		    {
		        int j=i;
		        string temp;
		        int pos=0;
		        while(j>0)
		        {
		            if(j&1)
		            {
		                temp.push_back(s[pos]);
		            }
		            pos++;
		            j>>=1;
		        }
		        ans.push_back(temp);
		        
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends
