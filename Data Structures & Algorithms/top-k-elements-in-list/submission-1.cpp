class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> freq;
        for(int i : nums){
            freq[i]++;
        }
        vector<pair<int, int>> pairs (freq.begin(), freq.end());
        sort(pairs.begin(), pairs.end(), [](pair<int, int> &left, pair<int, int>&right){
            return left.second > right.second;});
        for (int i=0; i<k; i++){
            auto &p = pairs[i];
            res.push_back(p.first);
        }
        return res;

    }
};
