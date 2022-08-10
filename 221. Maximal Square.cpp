//DP + Memoization
class Solution {
public:
    int solve(int i,int j,vector<vector<char>>& matrix,vector<vector<int>>&dp)
    {
        if(i==matrix.size()||j==matrix[0].size()||matrix[i][j]=='0')
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]=1+min({solve(i+1,j,matrix,dp),solve(i,j+1,matrix,dp),solve(i+1,j+1,matrix,dp)});
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,solve(i,j,matrix,dp));
            }
        }
        return ans*ans;
    }
};

//Tabulation
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
	    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
	    int ans = 0;
	    for(int i = m; i >= 0; i--) 
        {
		    for(int j = n; j >= 0; j--) 
            {
			    if(i == m || j == n || matrix[i][j] == '0') 
                    dp[i][j] = 0;
			    else 
                    dp[i][j] = 1 + min({dp[i][j + 1], dp[i + 1][j + 1], dp[i + 1][j]});
			    ans = max(ans, dp[i][j]);
		}
	}
        return ans*ans;
    }
};
