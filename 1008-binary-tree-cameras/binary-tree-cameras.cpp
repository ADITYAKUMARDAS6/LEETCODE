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
private:
    int cam = 0;
    
    int dfs(TreeNode* root) {
        if (!root) return 1;
        
        int leftCoverage = dfs(root->left);
        int rightCoverage = dfs(root->right);
        
        if (leftCoverage == 0 || rightCoverage == 0) {
            cam++;
            return 2; // Camera placed here
        } 
        else if (leftCoverage == 2 || rightCoverage == 2) {
            return 1; // Covered by child's camera
        } 
        else {
            return 0; // Needs to be covered by parent
        }
    }

public:
    int minCameraCover(TreeNode* root) {
        if (!root) return 0;
        int result = dfs(root);
        if (result == 0) cam++; // If the root is not covered, place a camera
        return cam;
    }
};
