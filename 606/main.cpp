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
    string tree2str(TreeNode* t) {
        string result;
        dfs(t, result);
        return result;
    }
    
private: 
    
    void dfs(TreeNode* node, string& result){
        if(!node){
            return;  
        }
        
        result += to_string(node->val);
        
        string tmp1 = "("; 
        dfs(node->left, tmp1);
        tmp1 += ")"; 
        string tmp2 = "("; 
        dfs(node->right, tmp2); 
        tmp2 += ")"; 
        
        if(tmp1 == "()" && tmp2 == "()"){
            return; 
        }
        else if(tmp1 != "()" && tmp2 == "()"){
            result += tmp1; 
        }
        else{
            result += tmp1; 
            result += tmp2;
        }
    }
};
