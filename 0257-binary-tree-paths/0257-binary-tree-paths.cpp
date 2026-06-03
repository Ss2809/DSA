/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<string>slove(TreeNode* root,vector<string>& ans , string path){
        if(root == nullptr){
            return ans ;
        }
        path += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(path);
            return ans ;
        }
        path += "->";
        slove(root->left,ans,path);
        slove(root->right, ans, path);
     return ans;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string path = "";
       return slove(root, ans, path);
    }
};