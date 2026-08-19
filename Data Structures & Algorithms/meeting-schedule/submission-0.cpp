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
        map<int, int> startTimes;
        map<int, int> endTimes;
        for(int i = 0; i < intervals.size(); i++){
            Interval& interval = intervals[i];
            if(startTimes.find(interval.start) != startTimes.end()){
                return false;
            }
            if(endTimes.find(interval.end) != endTimes.end()){
                return false;
            }
            startTimes[interval.start] = i;
            endTimes[interval.end] = i;
        }
        auto startIt = startTimes.begin();
        auto endIt = endTimes.begin();
        while(startIt != startTimes.end() && endIt != endTimes.end()){
            if(startIt->second == endIt->second){
                startIt++;
                endIt++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
