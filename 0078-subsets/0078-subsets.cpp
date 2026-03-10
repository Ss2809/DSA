

class Solution {
public:
  void slove(vector<int>& nums, int index,  vector<vector<int>> &ans, vector<int> &output){
    if( index == nums.size()){
        ans.push_back(output);
        return;
    }
    //include
    output.push_back(nums[index]);
    slove(nums,index+1, ans,output);
    output.pop_back();
    //exclude
    slove(nums, index+1, ans,output);
  }
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    slove(nums,index,ans,output);
    return ans;
        
    }
};