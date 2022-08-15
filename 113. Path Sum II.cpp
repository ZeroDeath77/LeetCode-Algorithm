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
    bool solve(TreeNode *root,vector<int>tmp,vector<vector<int>>&ans,int target)
    {
        if(!root)
        {
            return false;
        }
        if(!root->left and !root->right)
        {
            if(target==root->val)
            {
                tmp.push_back(root->val);
                ans.push_back(tmp);
                tmp.pop_back();
            }
            return target==root->val;
        }
        tmp.push_back(root->val);
        bool l=solve(root->left,tmp,ans,target-root->val);
        bool r=solve(root->right,tmp,ans,target-root->val);
        tmp.pop_back();
        return l | r;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        if(!root)
        {
            return ans;
        }
        vector<int>tmp;
        solve(root,tmp,ans,targetSum);
        return ans;
    }
};
