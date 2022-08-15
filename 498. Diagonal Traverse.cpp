class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>ans;
        int i=0,j=0;
        while(i!=m and j!=n)
        {
            while(i>=0 and j<n)
            {
                ans.push_back(mat[i--][j++]);
            }
            i++;
            j--;
            if(j<n-1)
            {
                j++;
            }
            else if(i<m-1)
            {
                i++;
            }
            else
            {
                break;
            }
            while(i<m and j>=0)
            {
                ans.push_back(mat[i++][j--]);
            }
            i--;
            j++;
            if(i<m-1)
            {
                i++;
            }
            else if(j<n-1)
            {
                j++;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
