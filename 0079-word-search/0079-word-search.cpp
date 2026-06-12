class Solution {
private:
    bool dfs(int i, int j, string word, vector<vector<char>>& board, int pos) {
        if (pos == word.size()) {
            return true;
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[pos]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '*';

        bool found =
            dfs(i + 1, j, word,board, pos + 1) || dfs(i - 1, j, word,board, pos + 1) ||
            dfs(i, j + 1, word,board, pos + 1) || dfs(i, j - 1, word,board, pos + 1);

        board[i][j] = temp;
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, word, board, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};