class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int* groups = new int[s.size()];
        
        int t = 0;
        groups[0] = 1;
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i-1] != s[i]) {
                groups[++t] = 1;
            } else {
                groups[t]++;
            }
        }

        int ans = 0;
        for (int i = 1; i <= t; i++) {
            ans += min(groups[i-1], groups[i]);
        }

        delete[] groups;
        
        return ans;
        
    }
};