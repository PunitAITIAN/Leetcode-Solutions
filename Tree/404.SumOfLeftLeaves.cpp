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
    void solve(TreeNode* root,int& ans){
        // base case
        if(root==NULL){
            return;
        }
        // left child hona chahiye and voh leaf hona chahiye
        if(root->left!=NULL){
            if(root->left->left==NULL && root->left->right==NULL){
                ans+=root->left->val;
            }
        }
        solve(root->left,ans);
        solve(root->right,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};