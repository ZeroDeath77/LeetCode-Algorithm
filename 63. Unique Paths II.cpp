//DP + Memoization
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid)
    {
        if(i>=0 and j>=0 and obstacleGrid[i][j]==1)
        {
            return 0;
        }
        if(i==0 and j==0)
        {
            return 1;
        }
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int left=solve(i,j-1,dp,obstacleGrid);
        int up=solve(i-1,j,dp,obstacleGrid);
        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp,obstacleGrid);
    }
};

//Tabulation + Space optimization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int>prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int>curr(n,0);
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    curr[j]=0;
                }
                else if(i==0 and j==0)
                {
                    curr[j]=1;
                }
                else
                {
                    int up=0,left=0;
                    if(i>0)
                    {
                        up=prev[j];
                    }
                    if(j>0)
                    {
                        left=curr[j-1];
                    }
                    curr[j]=up+left;
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};
