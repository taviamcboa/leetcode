/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution {
public:
    int min1;
    int ans = INT_MAX;

    void dfs(TreeNode* root) {
        if (root != 0) {
            if (min1 < root->val && root->val < ans) {
                ans = root->val;
            } else if (min1 == root->val) {
                dfs(root->left);
                dfs(root->right);
            }
        }
    }


    int findSecondMinimumValue(TreeNode* root) {
        min1 = root->val;
        dfs(root);
        return ans < INT_MAX ? ans : -1;
    }
};