class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        if (s.size() == 1) return s;
        for (int i=0; i<s.size(); i++){
            int l = i;
            int r = i;

            while(l>=0 && r<s.size()){
                if(s[l] == s[r]){
                    if(r-l + 1 > res.size()) res = s.substr(l, r-l+1);
                    l--;
                    r++;
                }
                else{                   
                    break;
                }
            }
        }

        for (int i=0; i<s.size(); i++){
            int l = i;
            int r = i+1;

            while(l>=0 && r<s.size()){
                if(s[l] == s[r]){
                    if(r-l+1 > res.size()) res = s.substr(l, r-l+1);
                    l--;
                    r++;
                }
                else{
                    break;
                }
            }

            if(l==-1 || r==s.size()){
                if(s[l+1] ==s[r-1]){
                    if(r-l-2 > res.size()) res = s.substr(l+1, r-l-2);
                    }
                cout << res;
            }
        }

        return res;

    }
};
