class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqCount;
        int len = nums.size();
        for(int i=0; i<len; i++){
            freqCount[nums[i]]++;
        }
        vector<pair<int, int>> orderedFreq(freqCount.begin(), freqCount.end());
        sort(orderedFreq.begin(), orderedFreq.end() ,
        [](const pair<int, int>&a, const pair<int, int>&b) {return a.second > b.second;});
        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(orderedFreq[i].first);
        }
        return res;
    }
};
