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
       if(root==NULL)
        {
            vector<vector<int>>ans;
            return ans;
        }
        vector<vector<int>>v;
        queue<TreeNode*>q;
        q.push(root);
        bool a=false;
        while(!q.empty())
        {vector<int>v1;
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                v1.push_back(curr->val);
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    q.push(curr->right);
                }
            }
            if(!a)
            {
                v.push_back(v1);
                a=true;
            }
            else
            {
                reverse(v1.begin(),v1.end());
                v.push_back(v1);
                a=false;
            }
            
            
        }
        return v;
    }
};