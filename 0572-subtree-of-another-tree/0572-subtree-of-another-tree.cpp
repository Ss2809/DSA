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
private:
    bool isSameTree(TreeNode* root, TreeNode* root1) {
        if (root == nullptr && root1 == nullptr) {
            return true;
        }
        if (root == nullptr || root1 == nullptr) {
            return false;
        }
        if (root->val != root1->val) {
            return false;
        }
        return isSameTree(root->left, root1->left) &&
              isSameTree(root->right, root1->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }
        if (isSameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};