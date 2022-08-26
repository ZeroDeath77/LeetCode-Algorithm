class Solution {
public:
    int solve(TreeNode *root,int prev,int tmp)
    {
        int flag=0;
        if(!root)
        {
            return tmp;
        }
        prev=max(prev,root->val);
        if(prev<=root->val)
        {
            flag=1;
        }
        tmp=solve(root->left,prev,tmp)+solve(root->right,prev,tmp)+flag;
        return tmp;
    }
    int goodNodes(TreeNode* root) {
        return solve(root,-1e9,0);
    }
};

=========================================================================================================
  
public:
    int ans=0;
    void solve(TreeNode *root,int prev)
    {
        if(!root)
        {
            return;
        }
        if(root->val>=prev)
        {
            ans++;
        }
        prev=max(prev,root->val);
        solve(root->left,prev);
        solve(root->right,prev);
    }
    int goodNodes(TreeNode* root) {
        solve(root,-1e9);
        return ans;
    }
};
