class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;
        for(char c : tasks)
            freq[c]++;

        priority_queue<int> pq;
        for(auto &p : freq)
            pq.push(p.second);

        int cycles = 0;

        while(!pq.empty()) {

            int time = 0;
            vector<int> temp;

            for(int i = 0; i <= n; i++) {
                if(!pq.empty()) {
                    int f = pq.top(); 
                    pq.pop();
                    if(f - 1 > 0)
                        temp.push_back(f - 1);
                    time++;
                }
            }

            for(int f : temp)
                pq.push(f);

            cycles += pq.empty() ? time : (n + 1);
        }

        return cycles;
    }
};
