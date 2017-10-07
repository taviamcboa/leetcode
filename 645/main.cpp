class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int twice, missing; 
        unordered_map<int, int> hashmap; 
        vector<int> result; 
        for(int i = 1; i <= n; i++){
            hashmap[i] = 1; 
        }
        
        for(int i = 0; i < nums.size(); i++){
            hashmap[nums[i]]++; 
        }

        for(unordered_map<int, int>::iterator iter = hashmap.begin(); iter != hashmap.end(); ++iter)
        {
            if(iter->second == 3){
                twice = iter->first; 
            }
            if(iter->second == 1){
                missing = iter->first; 
            }
        }
        
        result.push_back(twice); 
        result.push_back(missing);
        
        return result;
    }
};

