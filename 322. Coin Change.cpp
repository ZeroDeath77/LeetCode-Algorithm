//DP
class Solution {
public:
    int solve(int n,int amount,vector<int>& coins,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            if(amount%coins[n]==0)
            {
                return amount/coins[n];
            }
            else
            {
                return 1e9;
            }
        }
        if(dp[n][amount]!=-1)
        {
            return dp[n][amount];
        }
        int notpick=solve(n-1,amount,coins,dp);
        int pick=1e9;
        if(coins[n]<=amount)
        {
            pick=1+solve(n,amount-coins[n],coins,dp);
        }
        return dp[n][amount]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,amount,coins,dp);
        if(ans>=1e9)
        {
            return -1;
        }
        return ans;
    }
};

//Tabulation
int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
        
        for(int t = 0; t <= amount; t++){
            if(t % coins[0] == 0) prev[t] = t / coins[0];
            else prev[t] = 1e9;
        }
        //fill indexes
        for(int ind = 1; ind < n; ind++){
            for(int tar = 0; tar <= amount; tar++){
            int notPick = prev[tar];
            int pick = 1e9;
            if(coins[ind] <= tar) pick = 1 + curr[tar - coins[ind]];
             curr[tar] = min(pick, notPick);
            }
            prev = curr;
        }
        int ans =  prev[amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};

===========================================================================
  class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=amount;++j)
            {
                if(j==0)
                    dp[i][j] = 0;
                else if(i==0)
                    dp[i][j] = 1e5;
                else if(coins[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
            }
        }
        return dp[n][amount]>1e4 ? -1:dp[n][amount];
    }
};
