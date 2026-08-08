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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& postorderIndex,int inorderStart,int inorderEnd,unordered_map <int,int>& mapIndex){
        // base case
        if(postorderIndex<0){
            return NULL;
        }
        if(inorderStart>inorderEnd){
            return NULL;
        }

        int element = postorder[postorderIndex];
        postorderIndex--;

        TreeNode* root = new TreeNode(element);

        int index = mapIndex[element];

        root->right = solve(inorder,postorder,postorderIndex,index+1,inorderEnd,mapIndex);

        root->left = solve(inorder,postorder,postorderIndex,inorderStart,index-1,mapIndex);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // map for storing inorder and its index
        unordered_map <int,int> mapIndex;
        for(int i=0; i<inorder.size();i++){
            mapIndex.insert({inorder[i],i});
        }

        int postorderIndex = postorder.size()-1;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;

        return solve(inorder,postorder,postorderIndex,inorderStart,inorderEnd,mapIndex);
    }
};