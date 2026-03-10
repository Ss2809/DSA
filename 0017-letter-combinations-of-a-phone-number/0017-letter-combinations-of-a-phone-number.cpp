class Solution {
public:
    void slove(string digits, int index, vector<string>& ans, string output,
               vector<string>& mapping) {
        if (index == digits.length()) {
            ans.push_back(output);
            return;
        }
        int digit = digits[index] - '0';
        string value = mapping[digit];
        for (int i = 0; i < value.length(); i++) {
            slove(digits, index + 1, ans, output + value[i], mapping);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return {};

        vector<string> mapping = {"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        slove(digits, 0, ans, "", mapping);
        return ans;
    }
};