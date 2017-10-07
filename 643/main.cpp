class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN; 
        double totalPrevious = 0; 
        for(int i = 0; i < k; i++){
            totalPrevious += nums[i];
        }
        maxAvg = totalPrevious / k; 
        
        for(int i = k; i < nums.size(); i++){
            int dump_i = i - k; 
            int new_i = i; 
            
            totalPrevious += (nums[new_i] - nums[dump_i]);
            maxAvg = std::max(maxAvg, totalPrevious / k);
        }
        
        return maxAvg;
    }
};