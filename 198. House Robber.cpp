class Solution {
public:
    int solve(int id,vector<int>& nums,vector<int>&dp)
    {
        if(id==0)
        {
            return nums[0];
        }
        if(id<0)
        {
            return 0;
        }
        if(dp[id]!=-1)
        {
            return dp[id];
        }
        int pick=nums[id]+solve(id-2,nums,dp);
        int notpick=0+solve(id-1,nums,dp);
        return dp[id]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);
    }
};
