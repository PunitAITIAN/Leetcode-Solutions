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
    void preOrderTraversal(TreeNode* root , vector<int>& preOrder){
        // base case
        if(root==NULL) return;
        // Root Left Right
        // Root
        preOrder.push_back(root->val);
        // L
        preOrderTraversal(root->left , preOrder);
        // R
        preOrderTraversal(root->right , preOrder);
    }
    void flatten(TreeNode* root) {
        vector<int> preOrder;
        preOrderTraversal(root,preOrder);

        // now create a n nodes linkedlist 
        int n = preOrder.size();
        TreeNode* temp = root;
        while(n-1>0){

            // base case
            if(temp==NULL) temp = new TreeNode();

            // if left child exists , then make it null
            if(temp->left) temp->left=NULL;

            //if right child didn't exist then make it
            if(temp->right==NULL){
                temp->right = new TreeNode();
            }
            temp = temp->right;
            n--;
        }

        temp = root;

        // replace values with preOrder
        for(int i=0;i<preOrder.size();i++){
            temp->val=preOrder[i];
            temp = temp->right;
        }
    }
};