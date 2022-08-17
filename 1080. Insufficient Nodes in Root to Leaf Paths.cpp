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
    bool solve(TreeNode *root,int limit,int sum)
    {
        if(!root->left and !root->right)
        {
            if(sum+root->val>=limit)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool l=root->left?solve(root->left,limit,sum+root->val):false;
        bool r=root->right?solve(root->right,limit,sum+root->val):false;
        if(l==false)
        {
            root->left=NULL;
        }
        if(r==false)
        {
            root->right=NULL;
        }
        return l|r;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        bool flag=solve(root,limit,0);
        if(flag)
        {
            return root;
        }
        return nullptr;
    }
};
