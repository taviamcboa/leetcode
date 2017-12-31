class Solution {
public:
    bool checkRecord(string s) {
        int numA = 0; 
        int numLContinues = 0; 
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'A'){
                numA++; 
                numLContinues = 0; 
            }else if(s[i] == 'L'){
                numLContinues++; 
            }else{
                numLContinues = 0; 
            }
            
            if(numA > 1){
                return false; 
            }
            if(numLContinues > 2){
                return false;
            }
        }
        
        return true;
    }
};