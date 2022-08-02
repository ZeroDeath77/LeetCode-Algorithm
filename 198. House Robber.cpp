//DP+Memoization
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

//Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int take=nums[i];
            if(i>1)
            {
                take+=dp[i-2];
            }
            int nottake=0+dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[n-1];
    }
};

//Tabulation+SpaceOptimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=0;i<n;i++)
        {
            int take=nums[i];
            if(i>1)
            {
                take+=prev2;
            }
            int nottake=0+prev;
            int curr=max(take,nottake);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
