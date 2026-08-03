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

    void postOrderTraversal(TreeNode* root , vector <int>& ans){
        // base case 
        if(root==NULL){
            return;
        }
        // Left
        postOrderTraversal(root->left,ans);
        // Right
        postOrderTraversal(root->right,ans);
        // Root
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        // postOrder -> Left Right Root
        // vector for storing ans;
        vector<int> ans;

        postOrderTraversal(root,ans);

        return ans;
    }
};