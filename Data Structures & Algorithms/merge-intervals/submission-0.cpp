class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0]<b[0];});

        vector<vector<int>> result;

        for(auto it:intervals){
            if(result.size()==0) result.push_back(it);
            else{
                vector<int> curr = it;

                while(result.size()&&result.back()[1]>=curr[0]){
                    vector<int> back = result.back();
                    result.pop_back();
                    
                    curr[0]= min(curr[0], back[0]);
                    curr[1]= max(curr[1], back[1]);

                }
                result.push_back(curr);
            }
        }

        return result;
    }
};
