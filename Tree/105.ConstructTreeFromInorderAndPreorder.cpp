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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder , int& preOrderIndex , int inOrderStart , int inOrderEnd ,unordered_map<int,int>& mapIndex ){
        // base case
        if(preOrderIndex>=preorder.size()){
            return NULL;
        }
        if(inOrderStart > inOrderEnd){
            return NULL;
        }

        int element = preorder[preOrderIndex];
        preOrderIndex++;

        TreeNode* root = new TreeNode(element);

        int index = mapIndex[element];

        root->left = solve(preorder,inorder,preOrderIndex ,inOrderStart,index-1,mapIndex);

        root->right = solve(preorder,inorder,preOrderIndex ,index+1,inOrderEnd,mapIndex);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // map for storing preorder with index 
        unordered_map<int,int> mapIndex;
        for(int i=0;i<inorder.size();i++){
            mapIndex.insert({inorder[i],i});
        }

        int preOrderIndex=0;
        int inOrderStart =0;
        int inOrderEnd = inorder.size()-1;

        return solve(preorder,inorder,preOrderIndex,inOrderStart,inOrderEnd,mapIndex );
    }
};