class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int num = bits.size(); 
        vector<int> newVec(bits.begin(), bits.begin() + num - 1); 
        
        return isDecodable(newVec);
    }
    
private: 
    bool isDecodable(vector<int>& bits){
        if(bits.size() == 0){
            return true;
        }
        else if(bits.size() == 1){
            return bits[0] == 0; 
        }
        else if(bits.size() == 2){
            return bits[0] == 1 || bits[1] == 0; 
        }
        else{
            int num = bits.size(); 
            if(bits[num - 1] == 0){
                vector<int> newVec1(bits.begin(), bits.begin() + num - 1); 
                if(bits[num - 2] == 1){         
                     vector<int> newVec2(bits.begin(), bits.begin() + num - 2); 
                    return isDecodable(newVec1) || isDecodable(newVec2);           
                }else{
                    return isDecodable(newVec1);
                }
            }else{
                vector<int> newVec2(bits.begin(), bits.begin() + num - 2); 
                return bits[num - 2] == 1 && isDecodable(newVec2);
            }
        }
    }    
};