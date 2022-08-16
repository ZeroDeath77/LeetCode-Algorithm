class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totSum=0;
        int windowSum=0;
        int n=cardPoints.size();
        int l=0,r=n-k;
        for(int i=0;i<n;i++)
        {
            totSum+=cardPoints[i];
        }
        if(k==n)
        {
            return totSum;
        }
        for(int i=0;i<r;i++)
        {
            windowSum+=cardPoints[i];
        }
        int ans=totSum-windowSum;
        while(r<n)
        {
            windowSum+=cardPoints[r++];
            windowSum-=cardPoints[l++];
            ans=max(ans,totSum-windowSum);
        }
        return ans;
    }
};
