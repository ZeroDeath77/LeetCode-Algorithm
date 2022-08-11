//DP
class Solution {
public:
    int dp[601][101][101];
    int solve(vector<string>&strs,int m,int n,int i)
    {
        if((m==0 and n==0) || i<0)
        {
            return 0;
        }
        if(dp[i][m][n]!=-1)
        {
            return dp[i][m][n];
        }
        int zero=count(strs[i].begin(),strs[i].end(),'0');
        int one=strs[i].length()-zero;
        if(one<=n and zero<=m)
        {
            return dp[i][m][n]=max(1+solve(strs,m-zero,n-one,i-1),solve(strs,m,n,i-1));
        }
        else
        {
            return dp[i][m][n]=solve(strs,m,n,i-1);
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,m,n,strs.size()-1);
    }
};

//DP2
class Solution {
public:
 int DP[601][101][101];
    int fun(vector<string>& strs, int m,int n,int index)
    {
        if((m==0 && n==0) || index<0) return 0;
        if(DP[index][m][n]!=-1)return DP[index][m][n];
        int count_0=count(strs[index].begin(),strs[index].end(),'0');
        int count_1=strs[index].size()-count_0;
        if(count_1<=n && count_0<=m)
             return DP[index][m][n]=(max(1+fun(strs,m-count_0,n-count_1,index-1), fun(strs,m,n,index-1)));
        else
          return DP[index][m][n]=fun(strs,m,n,index-1);     
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(DP,-1,sizeof(DP));
        return fun(strs,  m,  n, strs.size()-1);
    }
};

===================================================================================================================
  class Solution {
    int fn(int idx, int m, int n, vector<string>& strs, vector<vector<vector<int>>> &dp){
        //base condition
        if(idx == 0) return 0;
        if(m == 0 and n == 0) return 0;
        
        if(dp[idx][m][n] != -1) return dp[idx][m][n];
        
        //count no. of zeros and ones
        int zero = 0 , one = 0;
        
        for(auto &x : strs[idx-1]){
            if(x == '0')
                zero++;
            else
                one++;
        }
        
        // can pick
        if(zero <= m and one <= n) 
            return dp[idx][m][n] = max(1+fn(idx-1, m-zero, n-one, strs, dp) , fn(idx-1, m, n, strs, dp));
        // not pick
        else
            return dp[idx][m][n] = fn(idx-1, m, n, strs, dp);
 
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        /// 3D vector
        vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(m+1 , vector<int>(n+1, -1)));
            
        return  fn(len, m, n, strs, dp);
    }
};

//Tabulation
class Solution {
public:
     int DP[601][101][101]; 
    int findMaxForm(vector<string>& strs, int m, int n) {
       memset(DP,0,sizeof(DP));
        
        for(int i=0;i<=strs.size();i++)
        {
        for(int M=0;M<=m;M++)
        {
            for(int N=0;N<=n;N++)
            {
                if((M==0 && N==0 )|| i==0) {
                    DP[i][m][n]=0;
                    continue;
                }
                   
                int count_0=count(strs[i-1].begin(),strs[i-1].end(),'0');
                int count_1=strs[i-1].size()-count_0;
                if(count_1<=N && count_0<=M)
                    DP[i][M][N]=(max((1+DP[i-1][M-count_0][N-count_1]), DP[i-1][M][N]));
                else
                    DP[i][M][N]=DP[i-1][M][N];
            }
        }
        }
        
        return DP[strs.size()][m][n];
    }
};

============================================================================================================
  class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        /// 3D vector
        vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(m+1 , vector<int>(n+1, 0)));
        
        for(int idx = 1 ;idx <= len; idx++){
            for(int j = 0 ; j <= m ;j++){
                for(int k = 0 ;k <= n;k++){
                    if(m == 0 and n == 0) continue;
                    int zero = 0 , one = 0;
        
                    for(auto &x : strs[idx-1]){
                        if(x == '0')
                            zero++;
                        else
                            one++;
                    }
                    if(zero <= j and one <= k)
                        dp[idx][j][k] = max(1 + dp[idx-1][j-zero][k-one] , dp[idx-1][j][k]);
                    else
                        dp[idx][j][k] = dp[idx-1][j][k];
                }
            }
        }
    
        return dp[len][m][n];
    }
};

//Tabulation + SO
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        
        vector<vector<int>> prev(m+1 , vector<int>(n+1, 0)) , curr(m+1 , vector<int>(n+1, 0));
        
        for(int idx = 1 ;idx <= len; idx++){
            for(int j = 0 ; j <= m ;j++){
                for(int k = 0 ;k <= n;k++){
                    if(m == 0 and n == 0) continue;
                    int zero = 0 , one = 0;
        
                    for(auto &x : strs[idx-1]){
                        if(x == '0')
                            zero++;
                        else
                            one++;
                    }
                    if(zero <= j and one <= k)
                        curr[j][k] = max(1 + prev[j-zero][k-one] , prev[j][k]);
                    else
                        curr[j][k] = prev[j][k];
                }
            }
            prev = curr;
        }
    
        return prev[m][n];
    }
};
