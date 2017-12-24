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
        vector<double> res; 

        queue<TreeNode*> bfs;
        bfs.push(root);
        
        while(bfs.empty() == false){
            long sum = 0; 
            // num of tree nodes in current level
            int s = bfs.size();
            for(int i = 0; i < s; i++) 
            {
             
                TreeNode* current = bfs.front(); 
                bfs.pop(); 

                if(current->left) 
                    bfs.push(current->left);
                if(current->right) 
                    bfs.push(current->right);
                
                sum += current->val; 
                
            }

            // push next level nodes
            
            res.push_back((double)sum / s);
            
            
        }
        
        return res; 
                   
    }
};