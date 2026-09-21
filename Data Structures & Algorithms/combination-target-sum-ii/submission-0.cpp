class Solution {
public:
    void combinations(std::vector<int>& nums, std::vector<int> candidate, int start, int target, std::vector<std::vector<int>>& res){

        if (target == 0){
            res.push_back(candidate);
            return;
        }

        if (target < 0) return;

        for (int i = start; i < nums.size(); i++){
            
            if (nums[i] > target) break;

            if (i > start && nums[i] == nums[i - 1]) continue;

            candidate.push_back(nums[i]);
            combinations(nums, candidate, i + 1, target - nums[i], res);
            candidate.pop_back();
        }
    

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        std::sort(candidates.begin(), candidates.end());

        std::vector<std::vector<int>> res = {};

        std::vector<int> candidate = {};

        combinations(candidates, candidate, 0, target, res);

        return res;

    }
};