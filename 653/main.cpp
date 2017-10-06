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
    bool findTarget(TreeNode* root, int k) {
        vector<int> orderedArray; 
        this->inOrderTraversal(root, orderedArray);
        
        int l, r; 
        l = 0; 
        r = orderedArray.size()-1; 
        
        while(l < r){
            if(orderedArray[l] + orderedArray[r] < k){
                l++; 
            }else if(orderedArray[l] + orderedArray[r] > k){
                r--; 
            }else{
                return true; 
            }
        }
        return false;
    }
    
private: 
    void inOrderTraversal(TreeNode* root, vector<int>& orderedArray){
        if(root && root->left){
            inOrderTraversal(root->left, orderedArray);
        }
    
        if(root){
            orderedArray.push_back(root->val);
        }
        
        if(root && root->right){
             inOrderTraversal(root->right, orderedArray);
        }
    }
};