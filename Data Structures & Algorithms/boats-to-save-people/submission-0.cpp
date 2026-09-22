class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;
        while(left <= right) {
            int weight_sum = people[left] + people[right];
            if(weight_sum > limit) {
                boats++;
                right--;
                continue;
            }
            boats++;
            right--;
            left++;
        }
        return boats;
    }
};