class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        int chardiff = 'A' - 'a';
        while (left <= right){
            char leftchar = tolower(s[left]);
            char rightchar = tolower(s[right]);

            if(isalpha(leftchar)==0 && isdigit(leftchar) == 0){
                left++;
                continue;
            }
            if(isalpha(rightchar)==0 && isdigit(rightchar) == 0){
                right--;
                continue;
            }
            if(leftchar == rightchar){
                left++;
                right--;
            }
            else return false;

        }
        return true;
    }
};
