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
    bool symmetry(TreeNode* p1, TreeNode* p2){
        if(!p1 && !p2) return true;
        if((!p1 && p2) || (p1 && !p2)) return false;
        if(p1->val!=p2->val) return false;
        bool left = symmetry(p1->left, p2->right);
        bool right = symmetry(p1->right, p2->left);
        if(left && right) return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
       return symmetry(root->left, root->right); 
    }
};