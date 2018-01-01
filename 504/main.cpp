class Solution {
public:
    string convertToBase7(int n) {
      return n>=0? n>=7? convertToBase7(n/7)+to_string(n%7) : to_string(n) : '-'+convertToBase7(-n);
    }

    string convertToBase7(int n) {
      int x = abs(n); 
      string res;
      do{
          res = to_string(x%7)+res; 
      }while(x/=7);
      return (n>=0? "" : "-") + res;
    }
};