class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        int pro = 1;
        int cnt = 0;
        int l = 0;

        for(int i = 0; i < nums.size(); i++) {
            pro *= nums[i];

            while(pro >= k) {
                pro /= nums[l];
                l++;
            }

            cnt += (i - l + 1);
        }

        return cnt;
    }
};