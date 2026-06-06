class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void backtrack(int start, vector<int>& nums) {
        ans.push_back(curr);

        for (int i = start; i < nums.size(); i++) {

            curr.push_back(nums[i]);   // choose

            backtrack(i + 1, nums);    // explore

            curr.pop_back();           // undo
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums);
        return ans;
    }
};