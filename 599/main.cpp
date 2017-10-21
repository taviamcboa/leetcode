class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        int leastIndexSum = INT_MAX; 
        vector<string> result; 
        
        unordered_map<string, pair<bool,int>> cache;
        for(int i = 0; i < list1.size(); i++){
            string key = list1[i]; 
            cache[key] = make_pair(false, i); 
        }
        
        for(int i = 0; i < list2.size(); i++){
            string key = list2[i]; 
            if(cache.count(key) > 0){
                
                cache[key].first = true; 
                cache[key].second += i; 
                
                if(cache[key].second < leastIndexSum){
                    leastIndexSum = cache[key].second; 
                    result.clear(); 
                    result.push_back(key); 
                    
                }else if(cache[key].second == leastIndexSum){
                    result.push_back(key); 
                }else{
                    
                }
            }
        }      
        return result;
    }
};