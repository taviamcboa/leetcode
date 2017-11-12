class Solution {
public:
    int findLHS(vector<int>& nums) {
        //dp 
        unordered_map<int, int> hash_map; 
        
        int maxLHS = 0; 
        
        for(int i = 0; i < nums.size(); i++){
            
            int v = nums[i]; 
            if(hash_map.count(v) > 0 ){
                hash_map[v]++; 
            } else{
                hash_map[v] = 1; 
            }
            
            if(hash_map.count(v - 1) > 0){
                maxLHS = max(maxLHS, hash_map[v] + hash_map[v-1]); 
            }
            
            if(hash_map.count(v + 1) > 0){
                maxLHS = max(maxLHS, hash_map[v] + hash_map[v+1]); 
            }
        }
        
        return maxLHS; 
    }
};