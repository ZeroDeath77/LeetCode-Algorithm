class Solution {
public:
    TreeNode* solve(vector<int>&nums,int l,int r)
    {
        if(l>r)
        {
            return nullptr;
        }
        int mid=(l+r)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=solve(nums,l,mid-1);
        root->right=solve(nums,mid+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,0,n-1);
    }
};
