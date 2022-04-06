class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int> m;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n<3 or nums[0]>0)
            return {};
        for(int i=0;i<n;i++)
        {
            m[nums[i]]=i;
        }
        vector<vector<int> > ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                break;
            if(i>0 and nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<n;j++)
            {
                if(j!=i+1 and nums[j]==nums[j-1])
                    continue;
                int sum=nums[i]+nums[j];
                sum*=-1;
                if(m.find(sum)!=m.end() and m[sum]>j)
                {
                    ans.push_back({sum,nums[i],nums[j]});
                }
            }
        }
        return ans;
    }
};
