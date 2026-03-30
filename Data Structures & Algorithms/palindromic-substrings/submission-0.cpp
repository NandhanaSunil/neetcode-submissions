class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() == 1) return 1;
        int n = 0;
        for(int i=0; i<s.size(); i++){
            int l = i;
            int r = i;

            while(l>=0 && r<s.size()){
                if(s[l] == s[r]){
                    n++;
                    l--;
                    r++;
                }
                else break;
            }
        }

        for(int i=0; i<s.size(); i++){
            int l = i;
            int r = i+1;

            while(l>=0 && r<s.size()){
                if(s[l] == s[r]){
                    n++;
                    l--;
                    r++;
                }
                else break;
            }
        }
        return n;
    }
};
