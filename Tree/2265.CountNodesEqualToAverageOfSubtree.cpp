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
    pair<int,int> solve(TreeNode* root ,int& ans){
        // base case
        if(root==NULL){
            return {0,0};
        }

        auto p1 = solve(root->left,ans);

        auto p2 = solve(root->right,ans);

        int totalsum = p1.first + p2.first + root->val;

        int totalcount = p1.second + p2.second + 1;

        // check
        if(root->val == totalsum/totalcount) ans++;

        return {totalsum , totalcount};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};