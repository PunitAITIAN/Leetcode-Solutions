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
    bool check(TreeNode* root,long long s , long long e){
        if(root==NULL){
            return true;
        }

        if(root->val <= s || root->val >= e){
            return false;
        }

        bool leftAns = check(root->left,s,root->val);

        bool rightAns = check(root->right,root->val,e);

        return leftAns && rightAns;
    }
    
    bool isValidBST(TreeNode* root) {
        long long s = LLONG_MIN;
        long long e = LLONG_MAX;

        return check(root,s,e);
    }
};