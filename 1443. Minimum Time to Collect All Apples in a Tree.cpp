class Solution {
public:
    int dfs(vector<bool>& hasApple, vector<vector<int>> &graph, int v, vector<bool> &vis)
    {
        if(vis[v])
        {
            return 0;
        }
        vis[v]=true;
        int sum=0;
        for(auto i:graph[v])
        {
            if(!vis[i])
            {
                sum+=dfs(hasApple,graph,i,vis);
            }
        }
        return (hasApple[v] and sum==0 and v!=0)||(sum>0 and v!=0)?sum+2:sum;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for(auto it:edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,false);
        return dfs(hasApple,graph,0,vis);
    }
};
