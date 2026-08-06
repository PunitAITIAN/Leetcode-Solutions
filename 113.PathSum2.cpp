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
    void solve(TreeNode* root, int targetSum, int sum ,vector<vector<int>>& ans,vector<int>& path ){
        // base case
        if(root==NULL){
            return ;
        }

        sum+=root->val;
        path.push_back(root->val);

        if(root->left==NULL && root->right==NULL){
            if(targetSum==sum){
                ans.push_back(path);
            }
            path.pop_back();
            return;
        }

        // left traverse
        solve(root->left,targetSum,sum,ans,path);
        // right traverse
        solve(root->right,targetSum,sum,ans,path);

        // backtrack
        path.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum =0;

        vector<vector<int>> ans;

        vector<int> path;

        solve(root,targetSum,sum,ans,path);

        return ans;
    }
};