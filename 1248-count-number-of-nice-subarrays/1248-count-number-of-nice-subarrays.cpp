class Solution {
public:
    int numberOfSubarrays1(vector<int>& nums, int k) {
        int l = 0;
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i< nums.size(); i++){
            cnt+= nums[i]%2;
            while(cnt > k){
                cnt -= nums[l]%2;
                l++;
            }
            ans += (i-l+1);
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k){
        return numberOfSubarrays1(nums, k)-numberOfSubarrays1(nums, k-1);
    }
}; 