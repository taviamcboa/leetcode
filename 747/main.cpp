class Solution {
public:
// find the largest two numbers in one pass. 
    int dominantIndex(vector<int>& nums) {
        
        int sec_i = -1;
        int max_i = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (max_i == -1 || nums[i] > nums[max_i]) {
                sec_i = max_i;
                max_i = i;
            }
            else if (sec_i == -1 || nums[i] > nums[sec_i]) {
                sec_i = i;
            }
        }
        if (nums[max_i] >= nums[sec_i] * 2) return max_i;
        return -1;
    }
};