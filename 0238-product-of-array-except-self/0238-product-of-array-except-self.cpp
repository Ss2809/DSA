class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        int perfix = 1;
        for(int i = 0; i < n; i++){
            ans[i] = perfix;
            perfix *= nums[i];
        }
        int suffix = 1;
        for(int i = nums.size()-1; i>= 0; i--){
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        return ans;
    }
};