class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& image, int newcolor,
             int oldcolor) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] == newcolor || image[i][j] != oldcolor){
                return;
            }
        image[i][j] = newcolor;
        dfs(i+1, j, image, newcolor, oldcolor);
        dfs(i, j+1, image, newcolor, oldcolor);
        dfs(i-1, j, image, newcolor, oldcolor);
        dfs(i, j-1, image, newcolor, oldcolor);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
       
        dfs(sr, sc, image, color, image[sr][sc]);
         return  image;
    }
};