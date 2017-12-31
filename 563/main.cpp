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
    int findTilt(TreeNode* root) {
        traverse(root); 
        return tilt; 
    }
    
private:
    int traverse(TreeNode* root)
    {
        if(root == NULL )
            return 0;
        int left = traverse(root->left);
        int right = traverse(root->right);
        tilt += abs(left-right);
        return left + right + root->val;
    }
    
    int tilt; 
};