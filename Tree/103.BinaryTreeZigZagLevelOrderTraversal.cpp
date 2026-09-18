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
    void solve(TreeNode* root ,vector<vector<int>>& ans,vector<int>& path){
        // base case
        if(root==NULL){
            return;
        }

        queue<TreeNode* >q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front!=NULL) path.push_back(front->val);
            if(front==NULL){
                ans.push_back(path);
                path.clear();

                if(!q.empty()) q.push(NULL);
            }
            else{
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int> path;
        vector<vector<int>> ans;
        solve(root,ans,path);
        // reverse odd no of vector in 2D Vector
        for(int i=0;i<ans.size();i++){
            if(i%2!=0){
                // odd numbered vector
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};