// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int> > > pq;
        for(int i=0;i<k;i++)
        {
            pq.push({arr[i][0],i,1});
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top()[0]);
            int tk=pq.top()[1];
            int ne=pq.top()[2];
            pq.pop();
            if(ne<k)
            {
                pq.push({arr[tk][ne],tk,ne+1});
            }
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends
