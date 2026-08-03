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
    void inOrderTraverse(TreeNode* root ,vector<int>& ans ){
        // base case
        if(root==NULL){
            return ;
        }
        // L
        inOrderTraverse(root->left,ans);
        // Root
        ans.push_back(root->val);
        // Right
        inOrderTraverse(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // inorder traversal -> Left Root Right
        vector<int> ans;
        inOrderTraverse(root,ans);
        return ans;
    }
};