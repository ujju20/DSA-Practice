class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        if(nums[0]==0)
            return -1;
        int maxReach=nums[0],step=nums[0],jump=1;
        int i=1;
        while(i<n)
        {
            if(i==n-1)
                return jump;
            maxReach=max(maxReach,i+nums[i]);
            step--;
            if(step==0)
            {
                jump+=1;
                if(i>=maxReach)
                    return -1;
                step=maxReach-i;
            }
            i++;
        }
        return -1;
    }
};
