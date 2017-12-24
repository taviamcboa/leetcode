class Solution {
public:
    bool hasAlternatingBits(int n) {
        // least mag digit
        int cur = n % 2;
        n /= 2;
        while (n > 0) {
            // neighboring digit has the same 1 or 0
            if (cur == n % 2) 
                return false;
            cur = n % 2;
            n /= 2;
        }
        return true;
    }
};