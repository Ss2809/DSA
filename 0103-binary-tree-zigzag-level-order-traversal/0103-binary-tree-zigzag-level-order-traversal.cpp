/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> ans;
        qu.push(root);
        bool flag = false;
        if (root == NULL)
            return {};
        while (!qu.empty()) {

            int size = qu.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {

                TreeNode* temp = qu.front();
                qu.pop();

                level.push_back(temp->val);

                if (temp->left)
                    qu.push(temp->left);

                if (temp->right)
                    qu.push(temp->right);
            }

            if (flag)
                reverse(level.begin(), level.end());

            ans.push_back(level);

            flag = !flag;
        }
        return ans;
    }
};