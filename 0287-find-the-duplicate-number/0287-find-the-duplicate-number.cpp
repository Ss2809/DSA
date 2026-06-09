class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>freq(nums.size(),0);
        for(auto i : nums){
            freq[i]++;
        } 
        for(int i = 0; i < freq.size(); i++){
            if(freq[i] >= 2){
                return i;
            }
        }
        return 0;
    }
};