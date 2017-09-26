/* If \text{p = 0}p = 0, then we could make the array good by setting \text{A[p] = A[p+1]}A[p] = A[p+1].
If \text{p = len(A) - 2}p = len(A) - 2, then we could make the array good by setting \text{A[p+1] = A[p]}A[p+1] = A[p].
Otherwise, \text{A[p-1], A[p], A[p+1], A[p+2]}A[p-1], A[p], A[p+1], A[p+2] all exist, and:
We could change \text{A[p]}A[p] to be between \text{A[p-1]}A[p-1] and \text{A[p+1]}A[p+1] if possible, or;
We could change \text{A[p+1]}A[p+1] to be between \text{A[p]}A[p] and \text{A[p+2]}A[p+2] if possible. */

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;                                                                    //the number of changes
        for(int i = 1; i < nums.size() && cnt<=1 ; i++){
            if(nums[i-1] > nums[i]){
                cnt++;
                if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];                    //modify nums[i-1] of a priority
                else nums[i] = nums[i-1];                                                //have to modify nums[i]
            }
        }
        return cnt<=1;
    } 
};