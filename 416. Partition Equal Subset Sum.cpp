//Tabulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
            return false;
        sum=sum/2;
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0)
                    dp[i][j]=false;
                if(j==0)
                    dp[i][j]=true;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j]; 
                else
                    dp[i][j]=dp[i-1][j]; 
            }
        }
        return dp[n][sum];
    }
};

//DP
bool eqsub(vector<int>& nums,int target,int idx,vector<vector<int>>&dp)
    {
        if(target==0)
            return true;
        if(idx==0)
            return nums[0]==target;
         if(dp[idx][target]!=-1)
             return dp[idx][target];
        bool no=eqsub(nums,target,idx-1,dp);
        bool yes=false;
        if(nums[idx]<=target)
            yes=eqsub(nums,target-nums[idx],idx-1,dp);
        return dp[idx][target]=no||yes;
    }
 bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int x:nums)
            sum+=x;
        if(sum%2!=0)
            return false;
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return eqsub(nums,sum/2,n-1,dp);
    }

//Tabulation + Space Optimization
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums)
        {
            sum+=x;
        }
        if(sum%2!=0)
        {
            return false;
        }
        sum/=2;
        vector<int>prev(sum+1,0),curr(sum+1,0);
        prev[0]=curr[0]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i]<=j)
                {
                    curr[j]=prev[j]||prev[j-nums[i]];
                }
                else
                {
                    curr[j]=prev[j];
                }
            }
            prev=curr;
        }
        return prev[sum];
    }
};
