class Solution {
public:

    void solve(vector<int>& nums, int index, vector<vector<int>>& ans, vector<int>& output){

        if(index == nums.size()){
            ans.push_back(output);
            return;
        }

        // include
        output.push_back(nums[index]);
        solve(nums, index+1, ans, output);

        output.pop_back();

        // exclude
        solve(nums, index+1, ans, output);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> output;

        sort(nums.begin(), nums.end());

        solve(nums, 0, ans, output);

        set<vector<int>> s(ans.begin(), ans.end());

        vector<vector<int>> result(s.begin(), s.end());

        return result;
    }
};