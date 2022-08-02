class Solution {
public:
    /*void solve(vector<vector<int>>& grid,int n,int m,int i,int j,int &count,int &res)
    {
        if(i<0||i>=n||j<0||j>=m||grid[i][j]==1)
        {
            return;
        }
        if(i==n and j==m)
        {
            res=min(res,count);
            return;
        }
        count++;
        grid[i][j]=1;
        solve(grid,n,m,i+1,j,count,res);
        solve(grid,n,m,i-1,j,count,res);
        solve(grid,n,m,i,j+1,count,res);
        solve(grid,n,m,i,j-1,count,res);
        solve(grid,n,m,i+1,j-1,count,res);
        solve(grid,n,m,i+1,j+1,count,res);
        solve(grid,n,m,i-1,j+1,count,res);
        solve(grid,n,m,i-1,j-1,count,res);
        grid[i][j]=0;
        count--;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=1;
        int res=INT_MAX;
        solve(grid,n,m,0,0,count,res);
        return res==INT_MAX?-1:res;
    }*/
    vector<int> dr = {-1,1,0,0,-1,-1,1,1};
    vector<int> dc = {0,0,1,-1,-1,1,-1,1};
    bool isValid(int row, int col,int ROW,int COL)
    {
     if (row < 0 || col < 0 || row >= ROW || col >= COL)
         return false;
     else
         return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[0][0] == 1) 
            return -1;
        if(grid[m-1][n-1] == 1) 
            return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        
        while(!q.empty()){
            auto curr = q.front();q.pop();
            
            for(int i = 0; i < 8; i++){
                
                int nr = curr.first + dr[i];
                int nc = curr.second+ dc[i];
                
                if(!isValid(nr,nc,m,n) || grid[nr][nc] != 0) 
                    continue;
                
                grid[nr][nc] = grid[curr.first][curr.second] + 1;
                q.push({nr,nc});
            }
        }
        
        if(grid[m-1][n-1] == 0) 
            return -1;
        else
            return grid[m-1][n-1];
    }
};
