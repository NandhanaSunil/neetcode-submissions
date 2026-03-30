class Solution {
public:
    string minWindow(string s, string t) {
        
        // if (t.empty()) return "";
        unordered_map <char, int> charT, window;
        for(char c : t){
            charT[c]++;
        }
        pair<int, int> res {-1, -1};
        int l = -0;
        int reslen = INT_MAX;
        int need = charT.size();
        int have = 0;
        for(int i=0; i<s.length(); i++){
            char c = s[i];
            window[c]++;
            
            if (window[c] == charT[c]){
                have++;
            }
            while(have == need){
                if(i-l+1 < reslen){
                    reslen = i-l+1;
                    res = {l, i};
                }
                window[s[l]]--;
                if (charT.count(s[l]) && window[s[l]] < charT[s[l]]) have--;
                l++;
            }
        }
        return reslen == INT_MAX ? "" : s.substr(res.first, reslen);
    }
};
