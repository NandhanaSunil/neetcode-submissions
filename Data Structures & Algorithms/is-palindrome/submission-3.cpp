class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(char c : s){
            if(isalnum(c)) str += char(tolower(c));
        }
        cout << str << endl;
        for(int i=0; i<str.size()/2; i++){
            if(str[i] != str[str.size()-1-i]) {
                cout << str[i] << str[str.size()-1-i];
                return false;}
        }
        return true;
    }
};
