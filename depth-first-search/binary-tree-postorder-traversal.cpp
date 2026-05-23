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
public:
    void solve(TreeNode* root, vector<int>&k){
        if(root==NULL) return;
        solve(root->left, k);
        solve(root->right,k);
        k.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>k;
        solve(root, k);
        return k;
    }
};