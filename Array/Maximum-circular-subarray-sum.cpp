class Solution {
    int maxSubarrSum(vector<int> a)
    {
        int n=a.size();
        int curr_sum=0,max_sum=0;
        int neg=a[0];
        for(int i=0;i<n;i++)
        {
            curr_sum+=a[i];
            neg=max(neg,a[i]);
            if(curr_sum<0)
                curr_sum=0;
            max_sum=max(max_sum,curr_sum);
        }
        return max_sum==0?neg:max_sum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int max_sum=INT_MIN,temp_sum1=0,min_sum=INT_MAX,temp_sum2=0,sum=0;
        for(int i=0;i<n;i++)
        {
            temp_sum1+=nums[i];
            max_sum=max(max_sum,temp_sum1);
            temp_sum1=temp_sum1<0?0:temp_sum1;
            sum+=nums[i];
            temp_sum2+=nums[i];
            min_sum=min(min_sum,temp_sum2);
            temp_sum2=temp_sum2>0?0:temp_sum2;
        }
        if(sum==min_sum)
            return max_sum;
        return max(max_sum,sum-min_sum);
    }
};
