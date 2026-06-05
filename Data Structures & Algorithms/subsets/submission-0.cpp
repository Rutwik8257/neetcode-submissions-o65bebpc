class Solution {
    public:
    vector<vector<int>> ans;
    void backtrack(int idx,vector<int>&nums,vector<int>curr){
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        backtrack(idx+1,nums,curr);

        curr.pop_back();
        backtrack(idx+1,nums,curr);
    }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int>curr;
            backtrack(0,nums,curr);
            return ans;
                    }

                    };
