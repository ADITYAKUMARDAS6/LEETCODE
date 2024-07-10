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
    
    void flatten(TreeNode* a) {
        
        if(!a) return;

        // 1
        TreeNode* tmp = a->right;
        a->right=a->left;
        a->left=nullptr;

        // 2
        TreeNode* rightMost=a;
        while(rightMost->right)
            rightMost=rightMost->right;

        // 3
        rightMost->right=tmp;
        // 4
        flatten(a->right);
    }

};