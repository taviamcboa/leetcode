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

// use stack 
class Solution {
public:
    int findUnsortedSubarray(vector<int> nums) {
        stack<int> stack; 
        int l = nums.size(), r = 0;
        for(int i = 0; i < nums.size(); i++) {
            while(!stack.empty() && nums[stack.top()] > nums[i]){
                l = min(l, stack.top());
                stack.pop();
            }
            
            stack.push(i);
        }
        
        while(!stack.empty()){
            stack.pop();
        }
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!stack.empty() && nums[stack.top()] < nums[i]){
                r = max(r, stack.top());
                stack.pop(); 
            }
            stack.push(i);
        }
        return r - l > 0 ? r - l + 1 : 0;
    }
};