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
    void solve(TreeNode* root, int k,int& index,int& ans){
        // base case
        if(root==NULL){
            return ;
        }
        // left 
        solve(root->left,k,index,ans);
        // root
        
        if(index==k){
            ans= root->val;
        }
        index++;
        
        // right
        solve(root->right,k,index,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int index =1;
        int ans;
        solve(root,k,index,ans);
        return ans;
    }
};