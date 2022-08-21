class Solution {
public:
    int count=0;
    int size;
    void solve(vector<int>&perm,int i)
    {
        if(i==size)
        {
            count++;
            return;
        }
        for(int k=i;k<size;k++)
        {
            if(i%perm[k]==0 || perm[k]%i==0)
            {
                swap(perm[k],perm[i]);
                solve(perm,i+1);
                swap(perm[k],perm[i]);
            }
        }
        return;
    }
    int countArrangement(int n) {
        vector<int>perm(n+1,0);
        size=n+1;
        for(int i=1;i<=n;i++)
        {
            perm[i]=i;
        }
        solve(perm,1);
        return count;
    }
};
