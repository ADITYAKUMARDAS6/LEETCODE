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
    int height(TreeNode* node, int& diameter) {
        // Base case: If the node is null,
        // return 0 indicating the
        // height of an empty tree
        if (!node) {
            return 0;
        }

        // Recursively calculate the
        // height of left and right subtrees
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        // Update the diameter with the maximum
        // of current diameter or sum of
        // left and right heights
        diameter = max(diameter, lh + rh);

        // Return the height of
        // the current node's subtree
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int dia=0;
        height(root,dia);
        return dia;
    }
};