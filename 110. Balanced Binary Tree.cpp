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
    int solve(TreeNode *root, int &flag)
    {
        int l=0,r=0;
        if(!root)
        {
            return 0;
        }
        l=solve(root->left,flag);
        r=solve(root->right,flag);
        if(abs(l-r)>1)
        {
            flag=0;
        }
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        int flag=1;
        solve(root,flag);
        return flag;
    }
};
