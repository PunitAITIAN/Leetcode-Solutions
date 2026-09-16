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
    void solve(TreeNode* root , vector<string>& ans , string s){
        // base case
        if(root==NULL){
            return ;
        }
        // leaf node
        if(root->left==NULL && root->right==NULL){
            s+=to_string(root->val);
            ans.push_back(s);
            return;
        }
        // 1 kaam karo baaki recursion dekh lega
        s+=to_string(root->val);
        s.push_back('-');
        s.push_back('>');
        // left
        solve(root->left,ans,s);
        // right
        solve(root->right,ans,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s;
        solve(root,ans,s);
        return ans;
    }
};