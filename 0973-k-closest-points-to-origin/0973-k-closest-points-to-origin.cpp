class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>>qu;

        for(auto i : points){
            int x = i[0];
            int y = i[1];
            int dist = x*x+y*y;
            qu.push({dist, i});

            if(qu.size() > k){
                qu.pop();
            }
        }
       vector<vector<int>> ans;
        while(!qu.empty()){
        ans.push_back(qu.top().second);
           
            qu.pop();
        }
        return ans;
    }
};