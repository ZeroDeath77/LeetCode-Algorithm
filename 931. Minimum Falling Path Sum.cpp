//Recursion
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&matrix)
    {
        if(j<0 || j>=matrix[0].size())
        {
            return 1e9;
        }
        if(i==0)
        {
            return matrix[0][j];
        }
        int up=matrix[i][j]+solve(i-1,j,matrix);
        int ld=matrix[i][j]+solve(i-1,j-1,matrix);
        int rd=matrix[i][j]+solve(i-1,j+1,matrix);
        return min(up,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=INT_MAX;
        for(int j=0;j<m;j++)
        {
            maxi=min(maxi,solve(n-1,j,matrix));
        }
        return maxi;
    }
};

//DP + Memoization
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        if(j<0 || j>=matrix[0].size())
        {
            return 1e9;
        }
        if(i==0)
        {
            return matrix[0][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int up=matrix[i][j]+solve(i-1,j,matrix,dp);
        int ld=matrix[i][j]+solve(i-1,j-1,matrix,dp);
        int rd=matrix[i][j]+solve(i-1,j+1,matrix,dp);
        return dp[i][j]=min(up,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++)
        {
            maxi=min(maxi,solve(n-1,j,matrix,dp));
        }
        return maxi;
    }
};

//Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++)
        {
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int up=matrix[i][j]+dp[i-1][j];
                int ld=matrix[i][j];
                if(j-1>=0)
                {
                    ld+=dp[i-1][j-1];
                }
                else
                {
                    ld+=1e9;
                }
                int rd=matrix[i][j];
                if(j+1<m)
                {
                    rd+=dp[i-1][j+1];
                }
                else
                {
                    rd+=1e9;
                }
                dp[i][j]=min(up,min(ld,rd));
            }
        }
        int mini=dp[n-1][0];
        for(int j=0;j<m;j++)
        {
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }
};

//Tabulation + Space optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>prev(n,0),curr(n,0);
        for(int j=0;j<m;j++)
        {
            prev[j]=matrix[0][j];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int up=matrix[i][j]+prev[j];
                int ld=matrix[i][j];
                if(j-1>=0)
                {
                    ld+=prev[j-1];
                }
                else
                {
                    ld+=1e9;
                }
                int rd=matrix[i][j];
                if(j+1<m)
                {
                    rd+=prev[j+1];
                }
                else
                {
                    rd+=1e9;
                }
                curr[j]=min(up,min(ld,rd));
            }
            prev=curr;
        }
        int mini=prev[0];
        for(int j=0;j<m;j++)
        {
            mini=min(mini,prev[j]);
        }
        return mini;
    }
};
