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
     int maxim = INT_MIN;
    int maxSum(TreeNode *root){
       
        if(root==NULL) return 0;
        int leftHeight = max(0,maxSum(root->left));
        int rightHeight = max(0,maxSum(root->right));
        maxim = max(maxim, root->val+leftHeight+rightHeight);
        return root->val+ max(0, max(leftHeight, rightHeight));
    }
    int maxPathSum(TreeNode* root) {
     maxSum(root);
     return maxim; 
    }
};