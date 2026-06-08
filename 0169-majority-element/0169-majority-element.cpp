class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candiate = 0;
        for(int i  : nums){
            if(cnt == 0){
                candiate = i;
            }
            if(candiate == i){
                cnt++;
            }else{
                cnt--;
            }
        }
        return candiate;
    }
};