class Solution {
public:
    int rec(vector<int> &nums, int index, int curr){
        if(index == nums.size()){
            return curr;
        }
        int include = rec(nums, index+1, curr^nums[index]);
        int exclude = rec(nums, index+1, curr);
         return include + exclude;
    }
    int subsetXORSum(vector<int>& nums) {
      return rec(nums, 0, 0);
    }
};