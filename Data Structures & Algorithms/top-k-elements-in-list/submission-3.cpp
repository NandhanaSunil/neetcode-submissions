class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int n: nums) freq[n]++;
        vector<vector<int>> freqmap(nums.size()+1);
        for(const auto&p : freq){
            freqmap[p.second].push_back(p.first);
        }
        vector<int> res;
        for(int i=nums.size(); i>=0; i--){
            for(int j: freqmap[i]) res.push_back(j);

            if (res.size() == k) return res;
        }
        return res;
    }
};
