class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size(); i++){
            if( (i-1 < 0 || flowerbed[i-1] == 0)  && flowerbed[i] == 0 && (i+1 >= flowerbed.size() || flowerbed[i+1] == 0)){
                n--; 
                flowerbed[i] = 1;                
            }
            
            if(n<=0){
                return true; 
            }
        }
        if(n==0){
                return true; 
            }else{
            return false;
        }
    }
};