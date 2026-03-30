/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<int>starts;
        vector<int>ends;
        for(auto inter : intervals){
            starts.push_back(inter.start);
            ends.push_back(inter.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for(int i=1; i<starts.size(); i++){
            if(starts[i] < ends[i-1]) return false;
        }
        return true;
    }
};
