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
        map<int,int> cnt;
        for(auto it:intervals){
            cnt[it.start]+=1;
            cnt[it.end]-=1;
        }
        int result = 0, curr=0;
        for(auto it:cnt){
            curr+=it.second;
            result = max(result, curr);
        }
        return result;
    }
};
