class Solution {
public:

    void permute(std::vector<int>& nums, std::vector<int>& candidate, std::vector<bool>& available, std::vector<std::vector<int>>& res){
        if (candidate.size() == nums.size()){
            res.push_back(candidate);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            if (available[i]){
                candidate.push_back(nums[i]);
                available[i] = false;
                permute(nums, candidate, available, res);
                candidate.pop_back();
                available[i] = true;
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        std::vector<std::vector<int>> res = {};

        std::vector<int> candidate = {};

        std::vector<bool> available(nums.size(), true);

        permute(nums, candidate, available, res);

        return res;

    }
};