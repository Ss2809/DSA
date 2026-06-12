class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one = 0;
        int two = 0;
        int zero =0;
        for(auto i : nums){
            if(i == 0) zero++;
            else if(i == 1) one++;
            else two++;
        }
        int k = 0;
        while(zero--) nums[k++] = 0;
        while(one--) nums[k++] = 1;
        while(two--) nums[k++] = 2;
    }
};