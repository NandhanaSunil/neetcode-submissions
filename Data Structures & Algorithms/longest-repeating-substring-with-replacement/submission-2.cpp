class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        if (s.size() < 2) return s.size();
        unordered_map <char, int> count;
        char c = s[0];
        count[c] = 1;
        int i = 1;
        int res = 1;
        while ( i < s.size()){
            count[s[i]]++;
            if (count[s[i]] > count[c]) c = s[i];
            if (((i-l+1) - count[c])>k){
                count[s[l]]--;
                l++;
            }
            cout << i << " " << l << i << endl;
            res = max(res, i-l+1);
            i++; 
        }
        return res;
    }
};
