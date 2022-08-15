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
    int convert(string s)
    {
        int sum=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            sum+=(s[i]-'0')*pow(2,n-1-i);
        }
        return sum;
    }
    void solve(TreeNode *root,int &totSum,string s)
    {
        if(root)
        {
            s+=to_string(root->val);
            if(!root->left and !root->right)
            {
                totSum+=convert(s);
                return;
            }
            solve(root->left,totSum,s);
            solve(root->right,totSum,s);
        }
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        int totSum=0;
        string s="";
        solve(root,totSum,s);
        return totSum;
    }
};
