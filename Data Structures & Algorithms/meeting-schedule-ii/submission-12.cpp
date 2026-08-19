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
        if(intervals.size() == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(),
        [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> min_heap;
        min_heap.push(intervals[0].end);
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start >= min_heap.top()) {
                min_heap.pop();
            }
            min_heap.push(intervals[i].start);
        }
        return min_heap.size();
    }
};
