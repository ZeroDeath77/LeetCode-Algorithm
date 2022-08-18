class Solution {
public:
    unordered_map<int,pair<int,int>>mp;
    void solve(TreeNode *root,int level,int parent)
    {
        if(!root)
        {
            return;
        }
        mp[root->val]={level,parent};
        solve(root->left,level+1,root->val);
        solve(root->right,level+1,root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        solve(root,0,-1);
        return mp[x].first==mp[y].first and mp[x].second!=mp[y].second;
    }
};

================================================================================================
class Solution {
public:
    int f=1;
    void solve(TreeNode* root,int x,int y,int &depthx,int &depthy,int depth){
        if(!root)
            return;
        depth++;
        if(root->left && root->right)
        {
            if((root->left->val== x ||root->right->val== x) && (root->left->val== y ||root->right->val== y ))
                f=0;
        }
        if(root->val==x)
            depthx=depth;
        if(root->val==y)
            depthy=depth;
        solve(root->left,x,y,depthx,depthy,depth);
        solve(root->right,x,y,depthx,depthy,depth);
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int depthx=0,depthy=0;
        int depth=0;
        solve(root,x,y,depthx,depthy,depth);
        return depthx==depthy && f==1;
    }
};
