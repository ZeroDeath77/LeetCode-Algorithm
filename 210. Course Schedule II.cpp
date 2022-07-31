class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans,ind(numCourses,0);
        vector<vector<int>>graph(numCourses,vector<int>());
        for(auto &it:prerequisites)
        {
            ind[it[0]]++;
            graph[it[1]].push_back(it[0]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty())
        {
            int tmp=q.front();
            q.pop();
            count++;
            ans.push_back(tmp);
            for(auto it:graph[tmp])
            {
                ind[it]--;
                if(ind[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if(count!=numCourses)
        {
            return {};
        }
        return ans;
    }
};
