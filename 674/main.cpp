class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        //dp 

        int maxLength = 0; 
        int length = 0; 
        bool restart = true; 
        int maximum = INT_MIN; 

        for(int i = 0; i < nums.size(); i++){
                if(nums[i] > maximum){
                    length++; 
                    maximum = nums[i];
                    maxLength = std::max(length, maxLength);
                }else{
                    restart = true; 
                    length = 1; 
                    maximum = nums[i]; 
                }
            
        }

        return maxLength; 
    }
};