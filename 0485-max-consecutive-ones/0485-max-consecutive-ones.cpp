class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0;
        int count = 0;
        int len = 0;
        for(int i = 0; i < nums.size() ; i++){
          if(nums[i] == 1){
           count++;
          }else{
            count = 0;
            l = i+1;
          }
           len  = max(len, i-l+1);
        }
        return len ;
    }
};