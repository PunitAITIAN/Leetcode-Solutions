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
    int findDepth(TreeNode* root){
        // base case
        if(root==NULL){
            return 0;
        }

        int leftDepth = findDepth(root->left);

        int rightDepth = findDepth(root->right);

        return 1+max(leftDepth,rightDepth);
    }

    bool isBalanced(TreeNode* root) {
        // if tree is empty , then it is already balanced
        if(root==NULL){
            return true;
        }

        int h1 = findDepth(root->left);
        int h2 = findDepth(root->right);

        if(abs(h1-h2)>1){
            // current node is not balanced
            return false;
        }
        else{
            // current node is balanced for sure
            // now check its left and right subtree

            // left subtree
            bool leftAns = isBalanced(root->left);
            // right subtree
            bool rightAns =  isBalanced(root->right);

            if(leftAns==true && rightAns==true){
                return true;
            }
            else{
                return false;
            }
        }
    }
};