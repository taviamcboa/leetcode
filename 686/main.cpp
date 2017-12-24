class Solution {
public:
// key point is the ending search condition: 
// A * k > lengthof(B), A* [k+1]
    int repeatedStringMatch(string A, string B) {
        
        int q = 0;
        int lengthA = A.size(); 
        int lengthB = B.size(); 
        
        string repeatA = ""; 
        
        while(repeatA.size() < lengthB){
            repeatA += A; 
            q++; 
        }
        
        std::size_t found = repeatA.find(B);
        if (found!=std::string::npos){
            return q; 
        }
        else{
            repeatA += A; 
            found = repeatA.find(B);
            if (found!=std::string::npos){
             return q + 1; 
            }
            else {
                return -1; 
            }
            
        }
    }
};