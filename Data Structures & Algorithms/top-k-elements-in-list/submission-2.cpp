class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i:nums){
            freq[i]++;
        }
        vector<pair<int,int>> pairs (freq.begin(), freq.end());
        sort(pairs.begin(), pairs.end(), [](pair<int, int>&a, pair<int,int>&b){
            return a.second > b.second;
        });
        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(pairs[i].first);
        }
        return res;
    }
};
