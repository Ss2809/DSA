class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int size = grid.size();
        int n = size*size;
       vector<int>freq(n+1,0);
       int repeat = -1;
       int miss = -1;
       for(auto i : grid){
        for(auto j : i){
            freq[j]++;
        }
       }

       for(int i = 1; i < n+1; i++) {
        if(freq[i] == 2) repeat = i;;
        if(freq[i] == 0) miss = i;
       }

       return {repeat, miss};
    }
};