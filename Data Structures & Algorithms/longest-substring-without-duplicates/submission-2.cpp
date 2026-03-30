class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int left = 0;
        int right = 1;
        if (s.size() < 2) return s.size();
        unordered_set <int> sub;
        sub.insert(s[left]);
        while (left<=right && right<s.size()){
            int sublen = 0;
            while(sub.count(s[right]) == 0 && right<s.size()){
                sub.insert(s[right]);
                right++;
            }
            len = max(len, (right - left));
            while (sub.count(s[right]) != 0){
                sub.erase(s[left]);
                left++;
            }
        }
        return len;
    }
};
