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
    // vector<int> adding(TreeNode * root,)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level;
        if (root==NULL) return level;
        queue<TreeNode*>q;
        q.push(root);
       while(!q.empty()){
        vector<int>l;
        int size = q.size();
        for(int i =0 ; i<size; i++){
            TreeNode* current = q.front();
            q.pop();
            l.push_back(current->val);
            if(current->left!=NULL) q.push(current->left);
            if(current->right!=NULL) q.push(current->right);
        }
        level.push_back(l);
       }
       return level;
    }
};

