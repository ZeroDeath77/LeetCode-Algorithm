class Solution {
public:
    bool solve(vector<vector<int>> &graph,vector<int> &vis,int s,int d)
    {
        if(s==d)
        {
            return true;
        }
        vis[s]=1;
        int temp=false;
        for(auto &it:graph[s])
        {
            if(!vis[it])
            {
                temp=temp||solve(graph,vis,it,d);
            }
            if(vis[it]!=0 and d==it)
            {
                return true;
            }
        }
        return temp;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n);
        vector<int>vis(n,0);
        for(auto &it:edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        return solve(graph,vis,source,destination);
    }
};
