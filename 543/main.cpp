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
    
private: 
    int maxSum; 
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root); 
        return this->maxSum; 
    }
    
    int traverse(TreeNode* root){
        if(!root){
            return 0; 
        }
        
        int left = traverse(root -> left); 
        int right = traverse(root -> right); 
        
        maxSum = max(maxSum, left + right); 
        
        return max(left, right) + 1; 
    }
};