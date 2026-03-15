class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // use two pointer 
        // ans store
        int n = nums.size();
        vector<int>ans(n) ;

        int left  = 0;
        int right = n-1;
        int pos = n-1;
        while(left <= right){
            int l = nums[left]*nums[left];
            int r = nums[right]*nums[right];

            if(l > r){
                ans[pos] = l;
               left++;
            }else{
                ans[pos] = r;
                right--;
            }
            pos--;
        }
        return ans;
    }
};