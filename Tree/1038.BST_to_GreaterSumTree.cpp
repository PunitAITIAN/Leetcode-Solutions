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
    void inorderTraverse(TreeNode* root, vector<int>& inorder){
        // base case
        if(root==NULL){
            return;
        }
        // left
        inorderTraverse(root->left,inorder);
        // root
        inorder.push_back(root->val);
        // right
        inorderTraverse(root->right,inorder);
    }
    void solve(TreeNode* root,vector<int>& inorder,int& index){
        // base case
        if(root==NULL){
            return;
        }
        // left
        solve(root->left,inorder,index);

        root->val = inorder[index];
        index++;
        
        // right
        solve(root->right,inorder,index);
    }
    TreeNode* bstToGst(TreeNode* root) {
        // base case
        if(root==NULL){
            return NULL;
        }

        if(root->left==NULL && root->right==NULL){
            return root;
        }

        // storing inorder
        vector<int> inorder;
        inorderTraverse(root,inorder);

        //updating inorder original value with suffix sum
        int sum = inorder[inorder.size()-1];
        for(int i=inorder.size()-2;i>=0;i--){
            sum+=inorder[i];
            inorder[i]=sum;
        }

        int index = 0;
        solve(root,inorder,index);

        return root;
    }
};