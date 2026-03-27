class Solution {
public:
    static bool compare(pair<int,int>& a, pair<int,int>& b){
        return a.second > b.second; 
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

       
        for(auto x : nums){
            mp[x]++;
        }

       
        vector<pair<int,int>> vec(mp.begin(), mp.end());

        
        sort(vec.begin(), vec.end(), compare);

        vector<int> ans;

      
        for(int i = 0; i < k; i++){
            ans.push_back(vec[i].first);
        }

        return ans;
    }
};