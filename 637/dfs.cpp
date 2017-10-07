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
    vector<double> averageOfLevels(TreeNode* root) {
        
        //dfs 
        vector<int> levelSum; 
        
        vector<int> levelCount; 
        
        vector<double> result; 
        
        
        dfs(root, 0, levelSum, levelCount); 
        
        
        for(int i = 0; i < levelSum.size(); i++){
            
            double sum = levelSum[i]; 
            
            result.push_back(sum/levelCount[i]); 
            
            
        }
        
        return result;
                   
    }
    
private: 
    void dfs(TreeNode* node, int level, vector<int>& levelSum, vector<int>& levelCount){
        if(!node){
            return; 
        }
        
        if(level >= levelSum.size()){
            
            levelSum.push_back(node->val); 
            levelCount.push_back(1);
            
        }else{
            
            levelSum[level] += node->val; 
            levelCount[level]++; 
            
        }
        
        dfs(node->left, level+1, levelSum, levelCount); 
        dfs(node->right, level+1, levelSum, levelCount); 
        
    }
};