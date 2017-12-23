class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
     // cost to arrive cost[0], cost[1] is 0
     int a=0, b=0, c;
     for(int i=2; i<=cost.size();i++){
         c = min(b+cost[i-1], a+cost[i-2]);
         a = b;
         b = c;
     }
     return c;
    }
};
