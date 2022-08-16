class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg=0;
        int n=nums.size();
        for(int i=0;i<k;i++)
        {
            avg+=nums[i];
        }
        double ans=avg;
        for(int i=k;i<n;i++)
        {
            avg+=(nums[i]-nums[i-k]);
            ans=max(ans,avg);
        }
        return ans/k;
    }
};
