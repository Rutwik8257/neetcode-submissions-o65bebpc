class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> val;

        for(int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            if(val.find(target - num) != val.end()){
                return {val[target - num], i};
            }
            val[num] = i;
        }
        return {};
    }
};