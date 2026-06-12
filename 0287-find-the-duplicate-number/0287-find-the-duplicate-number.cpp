class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int j = 1; j < nums.size(); j++) {
            if(nums[j] == nums[j - 1]) {
                return nums[j];
            }
        }
        return -1;
    }
};