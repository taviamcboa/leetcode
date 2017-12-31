class Solution {
public:
    string reverseWords(string s) {
        vector<string> words = this->splitSentence(s); 
        string result; 
        for(int i = 0; i < words.size(); i++){
            result += this->reverse(words[i]);
            if(i != words.size() - 1){
                result += ' '; 
            }
        }
        return result; 
    }
    
    
private:
    string reverse(string s){
        string result = s; 
        for(int i = 0; i < s.size(); i++){
            result[i] = s[s.size() - 1 - i]; 
            result[s.size() - 1- i] = s[i];
        }
        return result; 
    }
    
    vector<string> splitSentence(string s){
        vector<std::string> result;
        std::istringstream iss(s);
        for(std::string s; iss >> s; )
            result.push_back(s);
        
        return result;
    }
};