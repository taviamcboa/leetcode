class Solution {
public:
    bool judgeCircle(string moves) {
        int h, v; 
        h = v= 0; 
        
        for(int i = 0; i < moves.size(); i++){
            char c = moves[i]; 
            
            
            if(c == 'U'){
                v++; 
            }else if(c == 'D'){
                v--; 
            }else if(c == 'R'){
                h++; 
            }else{
                h--; 
            }
        }
        
        return h == 0 && v == 0;         
    }
};