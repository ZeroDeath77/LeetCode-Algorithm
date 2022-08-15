/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode *root,int target,vector<long long>&tmp,long long &cnt)
    {
        if(!root)
        {
            return;
        }
        tmp.push_back(root->val);
        solve(root->left,target,tmp,cnt);
        solve(root->right,target,tmp,cnt);
        long long sum=0;
        for(int i=tmp.size()-1;i>=0;i--)
        {
            sum+=tmp[i];
            if(sum==target)
            {
                cnt++;
            }
        }
        tmp.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<long long>tmp;
        long long cnt=0;
        solve(root,targetSum,tmp,cnt);
        return cnt;
    }
};
