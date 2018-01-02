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
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
    
private:
    int currVal;
    int currCount;
    int maxCount;
    
    vector<int> modes; 

    void handleValue(int val) {
        if (val != currVal) {
            currVal = val;
            currCount = 0;
        }
        
        currCount++;
        // new majority node occur. clear previous record
        if (currCount > maxCount) {
            maxCount = currCount;
            modes.clear(); 
            modes.push_back(val);
        } else if (currCount == maxCount) {
            // multipe node has the same count
            if (modes.size() > 0)
                modes.push_back(currVal);
        }
    }
    
     void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        handleValue(root->val);
        inorder(root->right);
    }
};