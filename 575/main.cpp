class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> kinds;
        for (int kind : candies) {
            kinds.insert(kind);
        }
        return min(kinds.size(), candies.size() / 2);
    }
};