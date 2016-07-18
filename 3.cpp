class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char,  int> myHash; 
        
        int i = 0;
        int maxLength = 0; 
        int length = 0; 
        int lastPos = -1;; 
        while(i < s.size())
        {
            if(myHash.count(s[i]) == 0 )
            {
                myHash.insert(make_pair(s[i], i)); 
                length++; 
            }
            else if(myHash[s[i]] < lastPos)
            {
                myHash[s[i]]= i; 
                length++; 
            }
            else
            {
                lastPos = myHash[s[i]]; 
                maxLength = max(length, maxLength); 
                length = i - lastPos;
                myHash[s[i]] = i; 
            }
            i++;
        }
        maxLength = max(length, maxLength); 
        return maxLength; 
    }
};
