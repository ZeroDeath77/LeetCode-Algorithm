class Solution {
public:
    int solve(string s1,string s2,string s3,int i,int j,int k,int a,int b,int c,vector<vector<int>>&dp)
    {
        if(i==a and j==b and k==c)
        {
            return true;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        bool x=false,y=false;
        if(i!=a)
        {
            if(s1[i]==s3[k])
            {
                x=solve(s1,s2,s3,i+1,j,k+1,a,b,c,dp);
            }
        }
        if(j!=b)
        {
            if(s2[j]==s3[k])
            {
                y=solve(s1,s2,s3,i,j+1,k+1,a,b,c,dp);
            }
        }
        return dp[i][j]=x||y;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int a=s1.size(),b=s2.size(),c=s3.size();
        if(a+b!=c)
        {
            return false;
        }
        vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
        return solve(s1,s2,s3,0,0,0,a,b,c,dp);
    }
};
