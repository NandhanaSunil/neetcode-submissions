class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue <pair<int, int>> pos_speed;

        for(int i=0; i<position.size(); i++){
            pos_speed.push({position[i], speed[i]});
        }
        int f = 0;
        vector <double> time;
        while (!pos_speed.empty()){
            pair<int, int> p = pos_speed.top();
            double t = (double)(target - p.first) / p.second;
            // cout << t << endl;
            time.push_back(t);
            pos_speed.pop();
        }
        int j = 0;
        while (j <position.size()){
            f++;
            double t = time[j];
            // cout << t << endl;
            j++;
            while(j <position.size() && (time[j] <= t)){
                // cout << time[j];
                j++;
            }

        }
        return f;
    }
};
