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
    bool isCompleteTree(TreeNode* root) {
        // level order traversal
        // rule
        // if there exists any element after NULL -> Not a CBT
        // if there doesn't exists any element after NULL -> CBT
        queue <TreeNode*> q;
        q.push(root);
        // null checker
        bool nullFound = false;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front==NULL){
                nullFound=true;
            }
            else{
                if(nullFound==true) return false;
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};