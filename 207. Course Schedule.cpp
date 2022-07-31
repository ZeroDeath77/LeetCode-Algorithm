class Solution {
public:
    bool checkCycle(int n,vector<vector<int>>&graph,vector<int>&vis,vector<int>&dfsvis)
    {
        vis[n]=1;
        dfsvis[n]=1;
        for(auto it:graph[n])
        {
            if(!vis[it])
            {
                if(checkCycle(it,graph,vis,dfsvis))
                {
                    return true;
                }
            }
            else if(dfsvis[it])
            {
                return true;
            }
        }
        dfsvis[n]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses+1);
        for(auto it:prerequisites)
        {
            graph[it[0]].push_back(it[1]);
        }
        vector<int>vis(numCourses,0),dfsvis(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(checkCycle(i,graph,vis,dfsvis))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
