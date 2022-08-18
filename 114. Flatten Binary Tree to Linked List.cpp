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
    void flatten(TreeNode* root) {
        TreeNode *curr=root;
        while(curr)
        {
            if(curr->left)
            {
                TreeNode *prev=curr->left;
                while(prev->right)
                {
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};

===================================================
  class Solution {
public:
    void dfs(TreeNode *&root, TreeNode *&prev) {
        if(root == NULL) return;
        
        dfs(root->right,prev);
        dfs(root->left,prev);
        
        root->right = prev;
        root->left = NULL;
        
        prev = root;
    }
    
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode *prev = NULL;        
        dfs(root, prev);
    }
};
