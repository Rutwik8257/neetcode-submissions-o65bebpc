class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r = n - 1;
        while(l<r){
            int currsum = nums[l] + nums[r];
            if(currsum > target){
                r--;
            }else if(currsum < target){
                l++;

            }else {
                return{l+1,r+1};
            }
        }
        return {};
    }
};
