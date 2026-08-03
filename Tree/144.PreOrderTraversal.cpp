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
    void preOrderTraversal(TreeNode* root , vector <int>& ans){
        // base case 
        if(root==NULL){
            return;
        }
        // Root
        ans.push_back(root->val);
        // Left
        preOrderTraversal(root->left,ans);
        // Right
        preOrderTraversal(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // preOrder -> Root Left Right
        // vector for storing ans;
        vector<int> ans;

        preOrderTraversal(root,ans);

        return ans;
    }
};