//Recursion
class Solution {
public:
    int solve(int i, int j1,int j2,int r,int c,vector<vector<int>>& grid)
    {
        if(j1<0||j2<0||j1>=c||j2>=c)
        {
            return -1e8;
        }
        else if(i==r-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1]+grid[i][j2];
            }
        }
        int maxi=-1e8;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                int val=0;
                if(j1==j2)
                {
                    val=grid[i][j1];
                }
                else
                {
                    val=grid[i][j1]+grid[i][j2];
                }
                val+=solve(i,j1+dj1,j2+dj2,r,c,grid);
                maxi=max(maxi,val);
            }
        }
        return maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        return solve(0,0,c-1,r,c,grid);
    }
};

//DP + Memoization
class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j1,int j2,int n,int m,vector<vector<vector<int>>>&dp){
        if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e9;
        if(i==n-1) {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi = INT_MIN;
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                int ans;
                if(j1==j2) ans = grid[i][j1]+solve(grid,i+1,j1+x,j2+y,n,m,dp);
                else ans = grid[i][j1]+grid[i][j2]+solve(grid,i+1,j1+x,j2+y,n,m,dp);
                maxi=max(ans,maxi);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m=grid[0].size();
         vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, vector < int> (m, -1)));
        return solve(grid,0,0,m-1,n,m,dp);
    }
};

//Tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, vector < int > (m, 0)));
        for (int j1 = 0; j1 < m; j1++) 
        {
            for (int j2 = 0; j2 < m; j2++) 
            {
                if (j1 == j2)
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                else
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
        for (int i = n - 2; i >= 0; i--) 
        {
            for (int j1 = 0; j1 < m; j1++) 
            {
                for (int j2 = 0; j2 < m; j2++) 
                {
                    int maxi = INT_MIN;
                    for (int di = -1; di <= 1; di++) 
                    {
                        for (int dj = -1; dj <= 1; dj++) 
                        {
                            int ans;    
                            if (j1 == j2)
                                ans = grid[i][j1];
                            else
                                ans = grid[i][j1] + grid[i][j2];
                            if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                                ans += -1e9;
                            else
                                ans += dp[i + 1][j1 + di][j2 + dj];
                            maxi = max(ans, maxi);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m - 1];
    }
};

//Tabulation + Space Optimization
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
          vector < vector < int >> front(m, vector < int > (m, 0)), cur(m, vector < int > 
  (m, 0));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        front[j1][j2] = grid[n - 1][j1];
      else
        front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += front[j1 + di][j2 + dj];

            maxi = max(ans, maxi);

          }
        }
        cur[j1][j2] = maxi;
      }
    }
    front = cur;
  }

  return front[0][m - 1];
        
    }
};
