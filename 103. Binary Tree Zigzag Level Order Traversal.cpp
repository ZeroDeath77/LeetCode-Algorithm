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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int flag=0;
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(!root)
        {
            return ans;
        }
        q.push(root);
        while(!q.empty())
        {
            vector<int>tmp;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
                if(node->left!=NULL)
                {
                   q.push(node->left);
                }
                tmp.push_back(node->val);
            }
            flag=!flag;
            if(flag%2!=0)
            {
                reverse(tmp.begin(),tmp.end());
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
