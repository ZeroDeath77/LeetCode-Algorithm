//DP + Memoization
class Solution {
public:
    int solve(int n,vector<int>&dp)
    {
        if(n<4)
        {
            return n;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int mini=10000;
        for(int i=sqrt(n);i>0;i--)
        {
            mini=min(mini,1+solve(n-i*i,dp));
        }
        return dp[n]=mini;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};

//Tabulation
class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int mini=10000;
            for(int j=1;j*j<=i;j++)
            {
                mini=min(mini,dp[i-j*j]);
            }
            dp[i]=mini+1;
        }
        return dp[n];
    }
};
