class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> freq(nums.size()+1,0);
        vector<int> ans(2);

        for(int n : nums){
            freq[n]++;
        }

        for(int i=1;i<=nums.size();i++){
            if(freq[i]==2) ans[0]=i;
            if(freq[i]==0) ans[1]=i;
        }

        return ans;
    }
};