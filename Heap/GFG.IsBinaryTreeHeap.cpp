/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    bool checkMaxHeap(Node* tree){
        // null node
        if(tree==NULL){
            return true;
        }
        
        // leaf node
        if(tree->left==NULL && tree->right==NULL){
            return true;
        }
        
        bool leftAns = checkMaxHeap(tree->left);
        bool rightAns = checkMaxHeap(tree->right);
            
        bool currentAns;
        // bas current node ko check karna pending h 
        // case 1 : only Left node exists 
        // case 2 : only right node exists
        // case 3 : both node exists
        bool leftChildCheck = true;
        bool rightChildCheck = true;
        
        if(tree->left && tree->data < tree->left->data){
            leftChildCheck = false;
        }
        
        if(tree->right && tree->data < tree->right->data){
            rightChildCheck = false;
        }
        
        currentAns = leftChildCheck && rightChildCheck;
    
        return (currentAns && leftAns && rightAns);
    }
    bool isCompleteBinaryTree(Node* tree){
        // if an element exists after NULL then its not a CBT
        // if no element exists after NULL , its a BST
        queue<Node*> q;
        
        q.push(tree);
        
        bool nullFound = false;
        
        while(!q.empty()){
            Node* front = q.front();
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
    bool isHeap(Node* tree) {
        // so for checking whether a binary is a heap or not 
        // we need to check 2 things
        // Complete Binary Tree
        // Max-Heap Property
        
        // if both conditions are satisfies , then it is a heap 
        // otherwise return false
        if(isCompleteBinaryTree(tree) && checkMaxHeap(tree)){
            return true;
        }
        else{
            return false;
        }
        
    }
};