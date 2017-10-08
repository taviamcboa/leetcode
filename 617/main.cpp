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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL){
            return t2;
        }
        if(t2 == NULL){
            return t1;
        }
        
        t1->val = t1->val + t2->val; 
        
        t1->left = mergeTrees(t1->left, t2->left); 
        
        t1->right = mergeTrees(t1->right, t2->right);
        
        return t1; 
    }
};



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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL){
            return t2; 
        }

        stack<pair<TreeNode*,TreeNode*>> dfs;  
        dfs.push(make_pair(t1, t2));

        while (!dfs.empty()) {
            pair<TreeNode* ,TreeNode*> t = dfs.top();
            dfs.pop(); 
  
            if (t.first == NULL || t.second == NULL) {
                continue;
            }

            t.first->val += t.second->val;
            
            if (t.first->left == NULL) {
                t.first->left = t.second->left;
            } else {
                dfs.push( make_pair(t.first->left, t.second->left) );
            }
            if (t.first->right == NULL) {
                t.first->right = t.second->right;
            } else {
                dfs.push( make_pair(t.first->right, t.second->right) );
            }
        }

        return t1;
    }
};
