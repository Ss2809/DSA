class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>map;

        for(int i : nums){
            map[i]++;
        }
        int ans = 0;
        for(auto i : map){
            int x = i.first;
            if(map.find(x+1) != map.end()){
                ans = max(ans, map[x]+map[x+1]);
            }
        }
        return ans;
    }
};