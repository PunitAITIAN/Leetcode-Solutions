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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 2D vector for storing ans;
        vector<vector<int>> ans;
        vector<int> path;

        queue<TreeNode*> q;

        if(root==NULL){
            return ans;
        }

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* fronti = q.front();  
            if(fronti) path.push_back(fronti->val);
            q.pop();

            if(fronti==NULL){
                // means a level is completed
                ans.push_back(path);
                // clear path
                path.clear();
                if(!q.empty()) q.push(NULL);
            }
            else{
                if(fronti->left){
                    q.push(fronti->left);
                }

                if(fronti->right){
                    q.push(fronti->right);
                }
            }
        }
        
        return ans;
    }
};