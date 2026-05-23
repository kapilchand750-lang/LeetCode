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
    int countHeight(TreeNode* root){
        int leftHeight = 0, rightHeight = 0;
        if(root==NULL) return 0;
        leftHeight = countHeight(root->left);
        rightHeight = countHeight(root->right);
        if (leftHeight == -1 || rightHeight == -1)
    return -1;

        if(abs(leftHeight - rightHeight)>1) return -1;
        return    1+ max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
         return countHeight(root) != -1;
    }
};