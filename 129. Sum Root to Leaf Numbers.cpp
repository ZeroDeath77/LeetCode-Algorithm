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
    int ans=0;
    void solve(TreeNode *root,int sum)
    {
        sum=sum*10+root->val;
        if(!root->left and !root->right)
        {
            ans+=sum;
        }
        if(root->left)
        {
            solve(root->left,sum);
        }
        if(root->right)
        {
            solve(root->right,sum);
        }
        return;
    }
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};

============================================================================================
class Solution {
public:
    
    int sum(TreeNode* root,int ans, int lv, int rv){
        
        if(root==NULL)
            return 0;
        
        if(root->left==NULL && root->right==NULL)
            return ans;
        
        if(root->left)
        lv=ans*10+root->left->val;
        
        if(root->right)
        rv=ans*10+root->right->val;
                
        return sum(root->left, lv, lv,rv) + sum(root->right, rv, lv,rv);
        
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) 
            return 0;
        
        return sum(root,root->val,0,0);
        
    }
};
