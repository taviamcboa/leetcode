class Solution {
public:
    int calPoints(vector<string>& ops) {
        int result = 0; 
        
        //double linked list
        list<int> validInput; 
        for(int i = 0; i < ops.size(); i++){
            int currentRoundPts; 
            const string input = ops[i];
            if(isNum(input)){
                currentRoundPts = std::stoi(input);
                validInput.push_front(currentRoundPts); 
            }else{
                if(input == "+"){
                        if(validInput.size() < 2){
                            throw "invalid input";
                        }
                        currentRoundPts = validInput.front() + *(++validInput.begin());
                        validInput.push_front(currentRoundPts);
                }else if(input == "D"){         
                        currentRoundPts = validInput.front() * 2;
                        validInput.push_front(currentRoundPts);
                }else if(input == "C"){
                        currentRoundPts = -validInput.front();
                        validInput.pop_front();
                }             
            }
            result += currentRoundPts; 
        }
        return result;
    }
    
    
private: 
    bool isNum(const string& word){
        bool isNumber = true;
        if(word[0] == '-'){
            for(string::const_iterator k = ++word.begin(); k != word.end(); ++k){
                isNumber = isNumber && isdigit(*k);
            }
        }else{
            for(string::const_iterator k = word.begin(); k != word.end(); ++k){
                isNumber = isNumber && isdigit(*k);
            }
        }
        return isNumber;
    }
};