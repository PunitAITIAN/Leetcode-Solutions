/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root==NULL){
            return NULL;
        }

        // 4 cases
        // case 1 : Both p and q in left subtree
        // then select left subtree and non-select right subtree
        if(p->val < root->val && q->val < root->val){
            TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
            if(leftAns!=NULL){
                return leftAns;
            }
        }
        // case 2 : Both p and q in right subtree
        // then select right subtree and non select left subtree
        if(p->val > root->val && q->val > root->val){
            TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
            if(rightAns!=NULL){
                return rightAns;
            }
        }
        // case 3 : p is in left subtree and q is in right subtree

        // case 4 : p is in right subree and q is in left subtree
        return root;
    }
};