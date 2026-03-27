class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // use max heap
        // top three ans is gold silver bronze after this pos right naaa
        priority_queue<pair<int, int>> qu;
        int n = score.size();
        for (int i = 0; i < n; i++) {
            qu.push({score[i], i});
        }
        // ans store
        vector<string> rank(n);
        int place = 1;
        while (!qu.empty()) {

            int index = qu.top().second;
            qu.pop();

            if (place == 1) {
                rank[index] = "Gold Medal";
            } else if (place == 2) {
                rank[index] = "Silver Medal";
            } else if (place == 3) {
                rank[index] = "Bronze Medal";
            } else {
                rank[index] = to_string(place);
            }
            place++;
        }
        return rank;
    }

    };