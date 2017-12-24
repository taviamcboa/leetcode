class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // record all the index in the original array
        
        unordered_map<int, vector<int>> hash; 
        
        for(int i = 0; i < nums.size(); i++){
            hash[nums[i]].push_back(i); 
        }
        
        int maxDegree = 0; 
        // calculate the max degree
        for( auto it = hash.begin(); it != hash.end(); ++it ){
             maxDegree = max(maxDegree, (int)it->second.size()); 
        }
        
        int minSpan = INT_MAX; 
        
        for( auto it = hash.begin(); it != hash.end(); ++it ){
             if(it->second.size() == maxDegree){
                 minSpan = min( minSpan, it->second[it->second.size() - 1] - it->second[0] + 1); 
             }
        }
        
        return minSpan;
    }
};