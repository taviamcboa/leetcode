class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortnums = nums; 
        std::sort (sortnums.begin(), sortnums.end());  
        
        int startIndex = sortnums.size() - 1; 
        int endIndex = 0; 
        
        for(int i = 0; i < nums.size(); i++){
            if(sortnums[i] != nums[i]){
                startIndex = min(startIndex, i);
                endIndex = max(endIndex, i); 
            }
        }
        
        return  endIndex > startIndex ? endIndex - startIndex + 1 : 0; 
    }
};