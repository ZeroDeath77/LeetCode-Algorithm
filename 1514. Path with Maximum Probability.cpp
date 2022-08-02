class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<vector<pair<int,double>>>graph(n);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>pq;
        vector<double>ans(n,0.0);
        vector<bool>vis(n,false);
        pq.push({1.0,start});
        ans[start]=1.0;
        while(!pq.empty())
        {
            double currval=pq.top().first;
            int curr=pq.top().second;
            pq.pop();
            vis[curr]=true;
            for(int i=0;i<graph[curr].size();i++)
            {
                double wt=graph[curr][i].second;
                int next=graph[curr][i].first;
                if(vis[next]==false)
                {
                    double nextprob=currval*wt;
                    if(nextprob>ans[next])
                    {
                        ans[next]=nextprob;
                    }
                    pq.push({nextprob,next});
                }
            }
        }
        return ans[end]==0.0?0.0:ans[end];
    }
};
