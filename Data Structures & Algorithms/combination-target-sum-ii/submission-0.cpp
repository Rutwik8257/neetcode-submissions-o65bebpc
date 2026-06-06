class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void backtrack(int start, vector<int>& nums, int target) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (target < 0)
            return;

        for (int i = start; i < nums.size(); i++) {

            if (i > start && nums[i] == nums[i - 1])
                continue;

            curr.push_back(nums[i]);

            backtrack(i + 1, nums, target - nums[i]);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        backtrack(0, nums, target);

        return ans;
    }
};