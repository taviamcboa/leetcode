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
        
        //bfs 
        vector<double> avgArray; 
        
        queue<pair<TreeNode*, int>> bfs;
        int currentLevelSum = 0; 
        int currentLevelCount = 0; 
        int previousLevel = -1;
        
        if(root){
            bfs.push(make_pair(root, 0)); 
        }else{
            return avgArray;
        }
        
        while(bfs.empty() ==false){
            pair<TreeNode*, int> tmp = bfs.front(); 
            bfs.pop();
            const TreeNode* currentNode = tmp.first; 
            const int currentLevel = tmp.second; 
            
            if(currentLevel != previousLevel){
                if(previousLevel != -1){
                    double avg = (double)currentLevelSum / currentLevelCount;
                    avgArray.push_back(avg);  
                }
                
                // reset
                currentLevelSum = 0; 
                currentLevelCount = 0; 
                previousLevel = currentLevel; 
                
            }  
            
            currentLevelSum += currentNode->val; 
            currentLevelCount++; 
            
            if(currentNode->left){
                bfs.push(make_pair(currentNode->left, currentLevel+1));
            }
            if(currentNode->right){
                bfs.push(make_pair(currentNode->right, currentLevel+1));
            }
        }
                         
       if(previousLevel != -1){
                    double avg = (double)currentLevelSum / currentLevelCount;
                    avgArray.push_back(avg);  
                }
          return avgArray;               
    }
};