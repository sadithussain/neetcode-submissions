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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;
        for(Interval& interval : intervals) {
            m[interval.start] += 1;
            m[interval.end] -= 1;
        }
        int max_rooms = 0;
        int rooms = 0;
        for(auto it = m.begin(); it != m.end(); it++) {
            rooms += it -> second;
            max_rooms = max(max_rooms, rooms);
        }
        return max_rooms;
    }
};
