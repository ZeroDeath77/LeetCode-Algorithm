class Solution {
public:
    TreeNode *solve(vector<int>& preorder,int preLeft,int preRight,vector<int>& inorder,int inLeft,int inRight,unordered_map<int,int>&imp)
    {
        if(preLeft>preRight || inLeft>inRight)
        {
            return NULL;
        }
        TreeNode *root=new TreeNode(preorder[preLeft]);
        int id=imp[preorder[preLeft]];
        int leftSize=id-inLeft;
        root->left=solve(preorder,preLeft+1,preLeft+leftSize,inorder,inLeft,id-1,imp);
        root->right=solve(preorder,preLeft+leftSize+1,preRight,inorder,id+1,inRight,imp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        unordered_map<int,int>imp;
        for(int i=0;i<n;i++)
        {
            imp[inorder[i]]=i;
        }
        return solve(preorder,0,n-1,inorder,0,n-1,imp);
    }
};
